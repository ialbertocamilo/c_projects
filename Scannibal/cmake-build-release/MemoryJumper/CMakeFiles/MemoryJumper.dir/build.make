# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\AlbertoCamilo\CLionProjects\Scannibal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release

# Include any dependencies generated for this target.
include MemoryJumper\CMakeFiles\MemoryJumper.dir\depend.make

# Include the progress variables for this target.
include MemoryJumper\CMakeFiles\MemoryJumper.dir\progress.make

# Include the compile flags for this target's objects.
include MemoryJumper\CMakeFiles\MemoryJumper.dir\flags.make

MemoryJumper\CMakeFiles\MemoryJumper.dir\main.cpp.obj: MemoryJumper\CMakeFiles\MemoryJumper.dir\flags.make
MemoryJumper\CMakeFiles\MemoryJumper.dir\main.cpp.obj: ..\MemoryJumper\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MemoryJumper/CMakeFiles/MemoryJumper.dir/main.cpp.obj"
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\MemoryJumper.dir\main.cpp.obj /FdCMakeFiles\MemoryJumper.dir\ /FS -c C:\Users\AlbertoCamilo\CLionProjects\Scannibal\MemoryJumper\main.cpp
<<
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release

MemoryJumper\CMakeFiles\MemoryJumper.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MemoryJumper.dir/main.cpp.i"
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\MemoryJumper.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\AlbertoCamilo\CLionProjects\Scannibal\MemoryJumper\main.cpp
<<
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release

MemoryJumper\CMakeFiles\MemoryJumper.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MemoryJumper.dir/main.cpp.s"
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MemoryJumper.dir\main.cpp.s /c C:\Users\AlbertoCamilo\CLionProjects\Scannibal\MemoryJumper\main.cpp
<<
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release

# Object files for target MemoryJumper
MemoryJumper_OBJECTS = \
"CMakeFiles\MemoryJumper.dir\main.cpp.obj"

# External object files for target MemoryJumper
MemoryJumper_EXTERNAL_OBJECTS =

MemoryJumper\MemoryJumper.dll: MemoryJumper\CMakeFiles\MemoryJumper.dir\main.cpp.obj
MemoryJumper\MemoryJumper.dll: MemoryJumper\CMakeFiles\MemoryJumper.dir\build.make
MemoryJumper\MemoryJumper.dll: MemoryJumper\CMakeFiles\MemoryJumper.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library MemoryJumper.dll"
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper
	"D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_dll --intdir=CMakeFiles\MemoryJumper.dir --rc=C:\PROGRA~2\WINDOW~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WINDOW~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\MemoryJumper.dir\objects1.rsp @<<
 /out:MemoryJumper.dll /implib:MemoryJumper.lib /pdb:C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper\MemoryJumper.pdb /dll /version:0.0 /machine:x64 /INCREMENTAL:NO  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  
<<
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release

# Rule to build all files generated by this target.
MemoryJumper\CMakeFiles\MemoryJumper.dir\build: MemoryJumper\MemoryJumper.dll

.PHONY : MemoryJumper\CMakeFiles\MemoryJumper.dir\build

MemoryJumper\CMakeFiles\MemoryJumper.dir\clean:
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper
	$(CMAKE_COMMAND) -P CMakeFiles\MemoryJumper.dir\cmake_clean.cmake
	cd C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release
.PHONY : MemoryJumper\CMakeFiles\MemoryJumper.dir\clean

MemoryJumper\CMakeFiles\MemoryJumper.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\AlbertoCamilo\CLionProjects\Scannibal C:\Users\AlbertoCamilo\CLionProjects\Scannibal\MemoryJumper C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper C:\Users\AlbertoCamilo\CLionProjects\Scannibal\cmake-build-release\MemoryJumper\CMakeFiles\MemoryJumper.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : MemoryJumper\CMakeFiles\MemoryJumper.dir\depend

