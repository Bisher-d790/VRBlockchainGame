�����, ������� ���� ������������ ��� ������ ����� ������ � ������ �������
�� Unreal Engine 4.9 ��� Android � �����������, ������������ OpenCV

MarkersDetector_Source - ����� �� ������������. ���������� � ��������, ������� ��� ����� � ������� ndk-build (��������� ���� � OpenCV � Android.mk).
ThirdParty - ���������������� ���������� ��� Win64 � Android, ������� h-�����. ����������� � ������ ������� �� UE4
MarkersDetector.dll - ���������� ��� Win64, ����������� � Binaries ������� �� UE4
WebcamReader.cpp � WebcamReader.h - C++ ����� ��� ���������� � ������ �� UE4. �� ���� ������ ���������� Blueprint.
MyProject5.Build.cs - ������������ ���������� � ����������� ����� ������ �������. ���������� ����� ThirdParty.

UnrealEngine - ����������, ���������� ������� ����� ����� ������������ ��� ������ ������ ������ UE � ���� ��� ���������:
UnrealEngine\jni - ��������� ������ � ���������� ��� ���������� Engine\Build\Android\Java\jni
UnrealEngine\GameActivity.java - ����, ������� ��������� ����������� ������ 
  System.loadLibrary("markersdetector"); 
  ����� 
  System.loadLibrary("UE4"); 
  � Engine\Build\Android\Java\src\com\epicgames\ue4\GameActivity.java

