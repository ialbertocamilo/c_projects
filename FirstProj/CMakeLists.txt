cmake_minimum_required(VERSION 3.15)
project(FirstProj)

set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(Qt5_DIR )

find_package(Qt5Widgets)
find_package(Qt5Core)
link_libraries(${Qt5Widgets_LIBRARIES})
add_executable(FirstProj main.cpp)
target_link_libraries(FirstProj gdiplus)
target_link_libraries(FirstProj Qt5::Widgets Qt5::Core)
