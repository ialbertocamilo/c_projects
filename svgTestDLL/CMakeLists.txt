cmake_minimum_required(VERSION 3.16)
project(svgTestDLL)

set(CMAKE_CXX_STANDARD 14)

add_library(svgTestDLL SHARED library.cpp library.h)