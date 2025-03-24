cmake_minimum_required(VERSION 3.16)

project(MultiThread-Gstreamer-RTSP-Live-With-Qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(OpenCV REQUIRED )
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Network )
find_package(Qt6 REQUIRED COMPONENTS Core Gui Network )

add_executable(MultiThread-Gstreamer-RTSP-Live-With-Qt
  main.cpp
  cameracapture.cpp
  cameracapture.h
  startprocess.cpp
  startprocess.h
  frameoperations.cpp
  frameoperations.h
  CamFrameId.h
)
target_link_libraries(MultiThread-Gstreamer-RTSP-Live-With-Qt Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui ${OpenCV_LIBS} Qt6::Network )

include(GNUInstallDirs)
install(TARGETS MultiThread-Gstreamer-RTSP-Live-With-Qt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
