cmake_minimum_required(VERSION 3.16)
project(InjectorC)

set(CMAKE_CXX_STANDARD 14)

add_executable(InjectorC main.cpp)
#target_link_libraries(InjectorC tlhelp32)