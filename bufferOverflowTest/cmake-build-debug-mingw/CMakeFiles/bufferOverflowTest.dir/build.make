# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lobo_\CLionProjects\bufferOverflowTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lobo_\CLionProjects\bufferOverflowTest\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/bufferOverflowTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bufferOverflowTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bufferOverflowTest.dir/flags.make

CMakeFiles/bufferOverflowTest.dir/main.cpp.obj: CMakeFiles/bufferOverflowTest.dir/flags.make
CMakeFiles/bufferOverflowTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lobo_\CLionProjects\bufferOverflowTest\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bufferOverflowTest.dir/main.cpp.obj"
	C:\Qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\bufferOverflowTest.dir\main.cpp.obj -c C:\Users\lobo_\CLionProjects\bufferOverflowTest\main.cpp

CMakeFiles/bufferOverflowTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bufferOverflowTest.dir/main.cpp.i"
	C:\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lobo_\CLionProjects\bufferOverflowTest\main.cpp > CMakeFiles\bufferOverflowTest.dir\main.cpp.i

CMakeFiles/bufferOverflowTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bufferOverflowTest.dir/main.cpp.s"
	C:\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lobo_\CLionProjects\bufferOverflowTest\main.cpp -o CMakeFiles\bufferOverflowTest.dir\main.cpp.s

# Object files for target bufferOverflowTest
bufferOverflowTest_OBJECTS = \
"CMakeFiles/bufferOverflowTest.dir/main.cpp.obj"

# External object files for target bufferOverflowTest
bufferOverflowTest_EXTERNAL_OBJECTS =

bufferOverflowTest.exe: CMakeFiles/bufferOverflowTest.dir/main.cpp.obj
bufferOverflowTest.exe: CMakeFiles/bufferOverflowTest.dir/build.make
bufferOverflowTest.exe: CMakeFiles/bufferOverflowTest.dir/linklibs.rsp
bufferOverflowTest.exe: CMakeFiles/bufferOverflowTest.dir/objects1.rsp
bufferOverflowTest.exe: CMakeFiles/bufferOverflowTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lobo_\CLionProjects\bufferOverflowTest\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bufferOverflowTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bufferOverflowTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bufferOverflowTest.dir/build: bufferOverflowTest.exe

.PHONY : CMakeFiles/bufferOverflowTest.dir/build

CMakeFiles/bufferOverflowTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bufferOverflowTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bufferOverflowTest.dir/clean

CMakeFiles/bufferOverflowTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lobo_\CLionProjects\bufferOverflowTest C:\Users\lobo_\CLionProjects\bufferOverflowTest C:\Users\lobo_\CLionProjects\bufferOverflowTest\cmake-build-debug-mingw C:\Users\lobo_\CLionProjects\bufferOverflowTest\cmake-build-debug-mingw C:\Users\lobo_\CLionProjects\bufferOverflowTest\cmake-build-debug-mingw\CMakeFiles\bufferOverflowTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bufferOverflowTest.dir/depend

