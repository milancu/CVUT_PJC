# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/InitB.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/InitB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InitB.dir/flags.make

CMakeFiles/InitB.dir/main.cpp.obj: CMakeFiles/InitB.dir/flags.make
CMakeFiles/InitB.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/InitB.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\InitB.dir\main.cpp.obj -c D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\main.cpp

CMakeFiles/InitB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InitB.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\main.cpp > CMakeFiles\InitB.dir\main.cpp.i

CMakeFiles/InitB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InitB.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\main.cpp -o CMakeFiles\InitB.dir\main.cpp.s

# Object files for target InitB
InitB_OBJECTS = \
"CMakeFiles/InitB.dir/main.cpp.obj"

# External object files for target InitB
InitB_EXTERNAL_OBJECTS =

InitB.exe: CMakeFiles/InitB.dir/main.cpp.obj
InitB.exe: CMakeFiles/InitB.dir/build.make
InitB.exe: CMakeFiles/InitB.dir/linklibs.rsp
InitB.exe: CMakeFiles/InitB.dir/objects1.rsp
InitB.exe: CMakeFiles/InitB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable InitB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\InitB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InitB.dir/build: InitB.exe
.PHONY : CMakeFiles/InitB.dir/build

CMakeFiles/InitB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\InitB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/InitB.dir/clean

CMakeFiles/InitB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\HW\InitB\cmake-build-debug\CMakeFiles\InitB.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/InitB.dir/depend

