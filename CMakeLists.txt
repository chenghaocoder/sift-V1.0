cmake_minimum_required(VERSION 3.12)
project(Main)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=c++11 -w")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -w")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=c++11 -w")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -w")

file(GLOB SIFT_SRC *.cpp *.h)

add_executable(SIFT ${SIFT_SRC})

# OpenCV
set(OpenCV_DIR "E:/opencv-2.4.9-mingw")
find_package(OpenCV 2.4.9 REQUIRED)
if (OpenCV_FOUND)
    INCLUDE_DIRECTORIES(${OPENCV_INCLUDE_DIRS})
    LINK_DIRECTORIES(${OPENCV_LIBRARY_DIRS})
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
endif ()

# 为可执行文件添加库链接，说明可执行文件需要链接后面这些库
target_link_libraries(SIFT ${OpenCV_LIBRARIES})

#file(GLOB IMG images/*)
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/images)
#foreach (img ${IMG})
#    configure_file(${img} images/ COPYONLY)
#endforeach ()
