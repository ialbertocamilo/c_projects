cmake_minimum_required(VERSION 3.14)
project(bufferOverflowTest)

set(masm intel)
set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-masm=intel")
#set(CMAKE_CXX_FLAGS "-fpermissive -std=c++0x")

add_executable(bufferOverflowTest main.cpp)