cmake_minimum_required(VERSION 2.8)
add_executable(Coursach Coursach.h Coursach.cpp)


set(OpenCV_DIR D:/programming/proga/opencv/build/x64/vc15/lib)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

link_directories(D:/programming/Anaconda1/envs/Coursach/libs)
include_directories(D:/programming/proga/pybind11/include/pybind11)
include_directories(D:/programming/Anaconda1/envs/Coursach/include)
include_directories(D:/programming/Anaconda1/envs/Coursach/libs)

target_link_libraries(Coursach ${OpenCV_LIBS} )
target_link_libraries(Coursach D:/programming/Anaconda1/envs/Coursach/libs/python36.lib )

set_property(TARGET Coursach PROPERTY CXX_STANDARD 14)