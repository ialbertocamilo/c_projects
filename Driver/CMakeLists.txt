cmake_minimum_required(VERSION 3.14)
project(Driver)

list(APPEND CMAKE_MODULE_PATH "C:\\Users\\lobo_\\Desktop\\Proyectos\\C\\FindWDK-master\\cmake")
find_package(WDK REQUIRED)
set(CMAKE_CXX_STANDARD 11)


wdk_add_driver(Driver
        KMDF 1.13
        WINVER 0x0A00
        main.c)


include_directories(win "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.18362.0\\km")
include_directories(kmdf "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\wdf\\kmdf\\1.15")
target_include_directories(Driver PUBLIC win kmdf)
target_link_libraries(Driver WDK::FLTMGR WDK::NTOSKRNL WDK::WDM WDK::WIN32K WDK::HAL)