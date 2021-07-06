cmake_minimum_required(VERSION 3.14)
project(Scannibal)

set(CMAKE_CXX_STANDARD 14)
#
#set(CMAKE_C_FLAGS -m32)
#set(CMAKE_CXX_FLAGS -m32)
#set(CMAKE_EXE_LINKER_FLAGS -m32)
set (mainFolder ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(MemoryJumper)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/svgLibrary)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/MemoryJumper)
add_library(Scannibal SHARED library.cpp library.h )
