Файлы, которые были использованы при записи видео ролика о сборке проекта
на Unreal Engine 4.9 под Android с библиотекой, использующей OpenCV

MarkersDetector_Source - можно не использовать. Директория с проектом, готовая для билда с помощью ndk-build (исправить путь к OpenCV в Android.mk).
ThirdParty - скомпилированные библиотеки под Win64 и Android, включая h-файлы. Скопировать в корень проекта на UE4
MarkersDetector.dll - библиотека под Win64, скопировать в Binaries проекта на UE4
WebcamReader.cpp и WebcamReader.h - C++ класс для добавления в проект на UE4. На этом классе базируется Blueprint.
MyProject5.Build.cs - использовать содержимое в аналогичном файле вашего проекта. Подключает папку ThirdParty.

UnrealEngine - директория, содержимое которой нужно будет использовать при правке файлов самого UE в пути его установки:
UnrealEngine\jni - параметры сборки и библиотеки для директории Engine\Build\Android\Java\jni
UnrealEngine\GameActivity.java - файл, который получился добавлением строки 
  System.loadLibrary("markersdetector"); 
  перед 
  System.loadLibrary("UE4"); 
  в Engine\Build\Android\Java\src\com\epicgames\ue4\GameActivity.java

