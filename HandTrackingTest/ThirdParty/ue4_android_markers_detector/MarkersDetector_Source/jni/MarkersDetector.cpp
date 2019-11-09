#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"

#include "MarkersDetector.h"
#include <numeric>
#include <map>
#include <array>
#include <iostream>

using namespace cv;
using namespace std;

float Marker::getPerimeter()
{
	float p = arcLength(points, true);
	return p;
}

string intToStr(int a)
{
	stringstream ss;
	ss << a;
    return ss.str();
}

int strToInt(string s)
{
	std::istringstream ss(s);
	int i;
	ss >> i;
	return i;
}



MarkersDetector::MarkersDetector(std::map <int, std::array<float, 3>>* markersLocations, std::array<double, 9> cameraMatrixBuf, std::array<double, 8> cameraDistortionBuf, int markerHalfSize)
{
	//std::map <int, std::array<float, 3>> ml = *markersLocations;
	typedef std::map <int, std::array<float, 3>>::iterator it_type;
	for (it_type iterator = markersLocations->begin(); iterator != markersLocations->end(); iterator++) {
		cv::Point3f p = { iterator->second[0], iterator->second[1], iterator->second[2] };
		m_markersLocations[iterator->first] = p;
	}


	m_cameraMatrix = Mat(3, 3, CV_64F);
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m_cameraMatrix.at<double>(i, j) = cameraMatrixBuf[k++];
		}
	}

	m_cameraDistortion = Mat(8, 1, CV_64F);
	for (int i = 0; i < 8; i++) {
		m_cameraDistortion.at<double>(0, i) = cameraDistortionBuf[i];
	}

	m_markerSize = Size(700, 700);
	m_markerCorners2d.push_back(Point(m_markerSize.width, 0));
	m_markerCorners2d.push_back(Point(m_markerSize.width, m_markerSize.height));
	m_markerCorners2d.push_back(Point(0, m_markerSize.height));
	m_markerCorners2d.push_back(Point(0, 0));

	float halfSize = markerHalfSize;
	m_markerCorners3d.push_back(Point3f(-halfSize, halfSize, 0));
	m_markerCorners3d.push_back(Point3f(-halfSize, -halfSize, 0));
	m_markerCorners3d.push_back(Point3f(halfSize, -halfSize, 0));
	m_markerCorners3d.push_back(Point3f(halfSize, halfSize, 0));
}

std::vector<Marker> MarkersDetector::detectMarkers(Mat frame)
{
	Mat grey = convertToGrey(frame);
	Mat binaryImg = performThreshold(grey);
	std::vector<std::vector<cv::Point>> contours = findContours(binaryImg);
	std::vector<Marker> markers = findPossibleMarkers(contours);
	markers = filterMarkersByPerimiter(markers);
	markers = filterMarkersByHammingCode(grey, markers);
	detectPreciseMarkerCorners(grey, markers);
	detectMarkersLocation(grey, markers);

	return markers;
}

Mat MarkersDetector::convertToGrey(Mat frame)
{
	Mat grey;
	cv::cvtColor(frame, grey, CV_BGRA2GRAY);
	return grey;
}

Mat MarkersDetector::performThreshold(Mat img)
{
	Mat binaryImg;
	//adaptiveThreshold(img, binaryImg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 7, 7);
	int method = THRESH_BINARY_INV | CV_THRESH_OTSU;
	if (threshold > 0) {
		method = THRESH_BINARY_INV;
	}
	cv::threshold(img, binaryImg, threshold, 255, method);

	//imshow("binary", binaryImg);

	return binaryImg;
}

std::vector<std::vector<cv::Point>> MarkersDetector::findContours(Mat binaryImg)
{
	std::vector<std::vector<cv::Point>> contours;
	int minContourPointsAllowed = 120;
	std::vector< std::vector<cv::Point> > allContours;
	cv::findContours(binaryImg, allContours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
	contours.clear();
	for (size_t i = 0; i<allContours.size(); i++)
	{
		int contourSize = allContours[i].size();
		if (contourSize > minContourPointsAllowed)
		{
			contours.push_back(allContours[i]);
		}
	}

	return contours;
}

std::vector<Marker> MarkersDetector::findPossibleMarkers(std::vector<std::vector<cv::Point>> contours)
{
	std::vector<Marker> possibleMarkers;

	std::vector<cv::Point> approxCurve;	

	// For each contour, analyze if it is a parallelepiped likely tobe the marker
	for (size_t i = 0; i<contours.size(); i++)
	{
		// Approximate to a polygon
		double eps = contours[i].size() * 0.05;
		cv::approxPolyDP(contours[i], approxCurve, eps, true);
		// We interested only in polygons that contains only fourpoints
		if (approxCurve.size() != 4)
			continue;
		// And they have to be convex
		if (!cv::isContourConvex(approxCurve))
			continue;
		// Ensure that the distance between consecutive points islarge enough
		float minDist = std::numeric_limits<float>::max();
		for (int i = 0; i < 4; i++)
		{
			cv::Point side = approxCurve[i] - approxCurve[(i + 1) % 4];
			float squaredSideLength = side.dot(side);
			minDist = std::min(minDist, squaredSideLength);
		}
		// Check that distance is not very small
		if (minDist < m_minContourLengthAllowed)
			continue;
		// All tests are passed. Save marker candidate:
		Marker m;
		for (int i = 0; i<4; i++)
			m.points.push_back(cv::Point2f(approxCurve[i].x, approxCurve[i].y));
		// Sort the points in anti-clockwise order
		// Trace a line between the first and second point.
		// If the third point is at the right side, then the points are anticlockwise
		cv::Point v1 = m.points[1] - m.points[0];
		cv::Point v2 = m.points[2] - m.points[0];
		double o = (v1.x * v2.y) - (v1.y * v2.x);
		if (o < 0.0) //if the third point is in the left side, then sort in anti - clockwise order
			std::swap(m.points[1], m.points[3]);

		possibleMarkers.push_back(m);
	}

	return possibleMarkers;
}

std::vector<Marker> MarkersDetector::filterMarkersByPerimiter(std::vector<Marker> possibleMarkers)
{
	std::vector<Marker> detectedMarkers;

	// Remove these elements which corners are too close to eachother.
	// First detect candidates for removal:
	std::vector< std::pair<int, int> > tooNearCandidates;
	for (size_t i = 0; i<possibleMarkers.size(); i++)
	{
		const Marker& m1 = possibleMarkers[i];
		//calculate the average distance of each corner to the nearest corner of the other marker candidate
		for (size_t j = i + 1; j<possibleMarkers.size(); j++)
		{
			const Marker& m2 = possibleMarkers[j];
			float distSquared = 0;
			for (int c = 0; c < 4; c++)
			{
				cv::Point v = m1.points[c] - m2.points[c];
				distSquared += v.dot(v);
			}
			distSquared /= 4;
			if (distSquared < 100)
			{
				tooNearCandidates.push_back(std::pair<int, int>(i, j));
			}
		}
	}
	// Mark for removal the element of the pair with smaller perimeter
	std::vector<bool> removalMask(possibleMarkers.size(), false);
	for (size_t i = 0; i<tooNearCandidates.size(); i++)
	{
		float p1 = possibleMarkers[tooNearCandidates[i].first].getPerimeter();
		float p2 = possibleMarkers[tooNearCandidates[i].second].getPerimeter();
		size_t removalIndex;
		if (p1 > p2)
			removalIndex = tooNearCandidates[i].second;
		else
			removalIndex = tooNearCandidates[i].first;
		removalMask[removalIndex] = true;
	}
	// Return candidates
	detectedMarkers.clear();
	for (size_t i = 0; i<possibleMarkers.size(); i++)
	{
		if (!removalMask[i])
			detectedMarkers.push_back(possibleMarkers[i]);
	}

	return detectedMarkers;
}

int MarkersDetector::getHammingError(Mat bitMatrix)
{
	int errors = 0;


	for (int row = 0; row < bitMatrix.rows; ++row) {
		int i1 = bitMatrix.at<uchar>(row, 0);
		int i2 = bitMatrix.at<uchar>(row, 1);
		int i3 = bitMatrix.at<uchar>(row, 2);
		int i4 = bitMatrix.at<uchar>(row, 3);
		int i5 = bitMatrix.at<uchar>(row, 4);

		int b1, b2, b4;

		if ((i3 + i5) % 2 == 0) {
			b1 = 1;
		}
		else {
			b1 = 0;
		}

		if (i3 == 1) {
			b2 = 0;
		}
		else {
			b2 = 1;
		}

		if (i5 == 1) {
			b4 = 0;
		}
		else {
			b4 = 1;
		}

		if (b1 != i1) {
			errors++;
		}
		if (b2 != i2) {
			errors++;
		}
		if (b4 != i4) {
			errors++;
		}
	}

	return errors;
}

Mat MarkersDetector::rotate90(Mat mat)
{
	Mat mat2;
	transpose(mat, mat2);
	flip(mat2, mat2, 1);
	return mat2;
}

int MarkersDetector::getHammingId(Mat bitMatrix)
{
	
	string idStr = "";
	for (int row = 0; row < bitMatrix.rows; ++row) {
		int i3 = bitMatrix.at<uchar>(row, 2);
		int i5 = bitMatrix.at<uchar>(row, 4);

		idStr += intToStr(i3) + intToStr(i5);
	}
	return strToInt(idStr);
}

std::vector<Marker> MarkersDetector::filterMarkersByHammingCode(Mat imgGrey, std::vector<Marker> possibleMarkers)
{
	std::vector<Marker> goodMarkers;

	for (size_t i = 0; i < possibleMarkers.size(); i++)
	{
		cv::Mat canonicalMarker;
		Marker& marker = possibleMarkers[i];
		// Find the perspective transfomation that brings current marker to rectangular form
		cv::Mat M = cv::getPerspectiveTransform(marker.points, m_markerCorners2d);
		// Transform image to get a canonical marker image
		cv::warpPerspective(imgGrey, canonicalMarker, M, m_markerSize);

		cv::threshold(canonicalMarker, canonicalMarker, 125, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);


		int cellSize = 100;

		cv::Rect r(cellSize, cellSize, m_markerSize.width - 2 * cellSize, m_markerSize.height - 2 * cellSize);
		cv::Mat subView = canonicalMarker(r);

		//imshow("canonical markers", subView);


		cv::Mat bitMatrix = cv::Mat::zeros(5, 5, CV_8UC1);
		//get information(for each inner square, determine if it is black or white)
		for (int y = 0; y<5; y++)
		{
			for (int x = 0; x<5; x++)
			{
				int cellX = (x)*cellSize;
				int cellY = (y)*cellSize;
				cv::Mat cell = subView(cv::Rect(cellX, cellY, cellSize, cellSize));
				int nZ = cv::countNonZero(cell);
				if (nZ>(cellSize*cellSize) / 2)
					bitMatrix.at<uchar>(y, x) = 1;
			}
		}


		//check all possible rotations
		cv::Mat rotations[4];
		int distances[4];
		rotations[0] = bitMatrix;
		distances[0] = getHammingError(rotations[0]);
		std::pair<int, int> minDist(distances[0], 0);
		for (int i = 1; i<4; i++)
		{
			//get the hamming distance to the nearest possible word
			rotations[i] = rotate90(rotations[i - 1]);
			distances[i] = getHammingError(rotations[i]);
			if (distances[i] < minDist.first)
			{
				minDist.first = distances[i];
				minDist.second = i;
			}
		}

		//sort the points so that they are always in the same order
		// no matter the camera orientation
		int nRotations = minDist.second;
		std::rotate(marker.points.begin(), marker.points.begin() + 4 - nRotations, marker.points.end());

		//get id
		marker.id = getHammingId(rotations[minDist.second]);

		if (minDist.first == 0) {
			goodMarkers.push_back(marker);
		}


	}

	return goodMarkers;
}

void MarkersDetector::detectPreciseMarkerCorners(Mat imgGrey, std::vector<Marker> &markers)
{
	std::vector<cv::Point2f> preciseCorners(4 * markers.size());
	for (size_t i = 0; i < markers.size(); i++)
	{
		Marker& marker = markers[i];
		for (int c = 0; c < 4; c++)
		{
			preciseCorners[i * 4 + c] = marker.points[c];
		}
	}
	if (preciseCorners.size() >= 4) {

		cv::cornerSubPix(imgGrey, preciseCorners, cvSize(5, 5), cvSize(-1, -1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.1));
		//copy back
		for (size_t i = 0; i<markers.size(); i++)
		{
			Marker &marker = markers[i];
			for (int c = 0; c<4; c++)
			{
				marker.points[c] = preciseCorners[i * 4 + c];
			}

		}
	}
}

void MarkersDetector::detectMarkersLocation(Mat imgGrey, std::vector<Marker> &markers)
{
	for (size_t i = 0; i < markers.size(); i++)
	{
		Marker& m = markers[i];
		cv::solvePnP(m_markerCorners3d, m.points, m_cameraMatrix, m_cameraDistortion, m.rotationVector, m.translationVector);
	}
}

void MarkersDetector::drawMarkers(Mat& image, std::vector<Marker> markers)
{
	for (size_t i = 0; i < markers.size(); i++)
	{
		Marker& m = markers[i];

		line(image, m.points[0], m.points[1], Scalar(255, 0, 255));
		line(image, m.points[1], m.points[2], Scalar(255, 0, 255));
		line(image, m.points[2], m.points[3], Scalar(255, 0, 255));
		line(image, m.points[3], m.points[0], Scalar(255, 0, 255));

		putText(image, "id:" + intToStr(m.id), m.points[2], CV_FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 255), 1, 2);
	}
}

void MarkersDetector::calculateCameraPose(std::vector<Marker> markers, map <int, cv::Point3f> markersLocations, cv::Point3f& camLocation, cv::Point3f& camRotation, int& usedMarkers)
{
	std::vector<cv::Point3f> cameraLocations;
	std::vector<cv::Point3f> cameraRotations;

	for (size_t i = 0; i < markers.size(); i++)
	{
		Marker& m = markers[i];

		if (markersLocations.find(m.id) == markersLocations.end()) {
			continue;
		}
		cv::Mat_<float> mLocMat = cv::Mat_<float>(markersLocations.at(m.id));

		cv::Mat R;
		cv::Rodrigues(m.rotationVector, R);
		cv::Mat cameraRotationVector;
		cv::Rodrigues(R.t(), cameraRotationVector);
		cv::Mat_<float> cameraTranslationVector = -R.t() * m.translationVector;

		Mat camLocationMat = mLocMat + cameraTranslationVector;
		Point3f camLocation(camLocationMat);

		cameraLocations.push_back(camLocation);
		cameraRotations.push_back(cv::Point3f(m.rotationVector));
	}

	usedMarkers = cameraLocations.size();

	if (usedMarkers > 0) {
		//calculate mean of points
		
		cv::Point3f zero(0.0f, 0.0f, 0.0f);
		cv::Point3f sumLoc = std::accumulate(cameraLocations.begin(), cameraLocations.end(), zero);
		Point3f meanLoc(sumLoc * (1.0f / cameraLocations.size()));
		camLocation = meanLoc;

		cv::Point3f sumRot = std::accumulate(cameraRotations.begin(), cameraRotations.end(), zero);
		Point3f meanRot(sumRot * (1.0f / cameraRotations.size()));
		camRotation = meanRot;
	}
}

void MarkersDetector::getCameraPoseByImage(Mat& frame, cv::Point3f& camLocation, cv::Point3f& camRotation, int& usedMarkers)
{
	std::vector<Marker> markers = detectMarkers(frame);
	drawMarkers(frame, markers);
	calculateCameraPose(markers, m_markersLocations, camLocation, camRotation, usedMarkers);

	if (usedMarkers > 0) {
		string s = "x=" + intToStr(camLocation.x) + ", y=" + intToStr(camLocation.y) + ", z=" + intToStr(camLocation.z) + "; used markers: " + intToStr(usedMarkers);
		putText(frame, s, Point(20, 20), CV_FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 255), 1, 2);

		string s2 = "r1=" + intToStr(camRotation.x) + ", r2=" + intToStr(camRotation.y) + ", r3=" + intToStr(camRotation.z);
		putText(frame, s2, Point(20, 50), CV_FONT_HERSHEY_COMPLEX, 0.5, Scalar(255, 0, 255), 1, 2);
	}
}

bool MarkersDetector::captureCamera(int cameraId, int width, int height)
{
	stream = new cv::VideoCapture();
	stream->open(cameraId);
	stream->set(CV_CAP_PROP_FRAME_WIDTH, width);
	stream->set(CV_CAP_PROP_FRAME_HEIGHT, height);
	
	m_isOpen = stream->isOpened();
	return m_isOpen;
}
void MarkersDetector::releaseCamera()
{
	stream->release();
	m_isOpen = false;
}

void MarkersDetector::update(std::vector<uchar>& buffer, std::array<float, 3>& camLocation, std::array<float, 3>& camRotation, int& usedMarkers)
{
	if (!m_isOpen) {
		return;
	}

	Mat frame;
	stream->read(frame);

	cv::Point3f cl;
	cv::Point3f cr;

	getCameraPoseByImage(frame, cl, cr, usedMarkers);

	(buffer).assign(frame.datastart, frame.dataend);

	camLocation[0] = cl.x;
	camLocation[1] = cl.y;
	camLocation[2] = cl.z;

	camRotation[0] = cr.x;
	camRotation[1] = cr.y;
	camRotation[2] = cr.z;
}