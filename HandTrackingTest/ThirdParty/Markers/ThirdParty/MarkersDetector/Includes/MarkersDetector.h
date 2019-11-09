#ifdef MARKERSDETECTORDLL_EXPORTS
#define MARKERSDETECTOR_API __declspec(dllexport) 
#else
  #ifndef __ANDROID__
    #define MARKERSDETECTOR_API __declspec(dllimport)
  #else
    #define MARKERSDETECTOR_API 
  #endif
#endif

#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <array>
#include <map>

using namespace cv;
using namespace std;

class Marker{

public:
	std::vector< cv::Point2f > points;
	int id;
	Mat translationVector;
	Mat rotationVector;

	float getPerimeter();

private:


};

class MARKERSDETECTOR_API MarkersDetector{

public:
	MarkersDetector(map <int, std::array<float, 3>>* markersLocations, std::array<double, 9> cameraMatrixBuf, std::array<double, 8> cameraDistortionBuf, int markerHalfSize);

	int threshold = 0;

	bool captureCamera(int cameraId, int width, int height);
	void releaseCamera();

	std::vector<Marker> detectMarkers(Mat frame);
	void drawMarkers(Mat& image, std::vector<Marker> markers);
	void calculateCameraPose(std::vector<Marker> markers, map <int, cv::Point3f> markersLocations, cv::Point3f& camLocation, cv::Point3f& camRotation, int& usedMarkers);


	void getCameraPoseByImage(Mat& frame, cv::Point3f& camLocation, cv::Point3f& camRotation, int& usedMarkers);

	void update(std::vector<uchar>& buffer, std::array<float, 3>& camLocation, std::array<float, 3>& camRotation, int& usedMarkers);

private:

	map <int, cv::Point3f> m_markersLocations;
	Mat_<double> m_cameraMatrix;
	Mat_<double> m_cameraDistortion;
	int m_minContourLengthAllowed = 1000;

	VideoCapture* stream;
	bool m_isOpen;

	Size m_markerSize;
	std::vector<Point2f> m_markerCorners2d;
	std::vector<Point3f> m_markerCorners3d;

	Mat convertToGrey(Mat frame);
	Mat performThreshold(Mat img);
	
	std::vector<std::vector<cv::Point>> findContours(Mat binaryImg);

	std::vector<Marker> findPossibleMarkers(std::vector<std::vector<cv::Point>> contours);

	std::vector<Marker> filterMarkersByPerimiter(std::vector<Marker> possibleMarkers);

	int getHammingError(Mat bitMatrix);
	Mat rotate90(Mat mat);
	int getHammingId(Mat bitMatrix);

	std::vector<Marker> filterMarkersByHammingCode(Mat imgGrey, std::vector<Marker> possibleMarkers);

	void detectPreciseMarkerCorners(Mat imgGrey, std::vector<Marker>& markers);

	void detectMarkersLocation(Mat imgGrey, std::vector<Marker>& markers);

};
