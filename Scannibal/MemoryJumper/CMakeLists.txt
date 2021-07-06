
set(APP_NAME MemoryJumper)
project(MemoryJumper)
include_directories(${mainFolder}/svgLibrary)
add_library(MemoryJumper SHARED main.cpp)