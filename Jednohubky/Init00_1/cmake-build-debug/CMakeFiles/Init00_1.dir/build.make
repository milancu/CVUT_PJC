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
CMAKE_SOURCE_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Init00_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Init00_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Init00_1.dir/flags.make

CMakeFiles/Init00_1.dir/main.cpp.obj: CMakeFiles/Init00_1.dir/flags.make
CMakeFiles/Init00_1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Init00_1.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Init00_1.dir\main.cpp.obj -c D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\main.cpp

CMakeFiles/Init00_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Init00_1.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\main.cpp > CMakeFiles\Init00_1.dir\main.cpp.i

CMakeFiles/Init00_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Init00_1.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\main.cpp -o CMakeFiles\Init00_1.dir\main.cpp.s

# Object files for target Init00_1
Init00_1_OBJECTS = \
"CMakeFiles/Init00_1.dir/main.cpp.obj"

# External object files for target Init00_1
Init00_1_EXTERNAL_OBJECTS =

Init00_1.exe: CMakeFiles/Init00_1.dir/main.cpp.obj
Init00_1.exe: CMakeFiles/Init00_1.dir/build.make
Init00_1.exe: CMakeFiles/Init00_1.dir/linklibs.rsp
Init00_1.exe: CMakeFiles/Init00_1.dir/objects1.rsp
Init00_1.exe: CMakeFiles/Init00_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Init00_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Init00_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Init00_1.dir/build: Init00_1.exe
.PHONY : CMakeFiles/Init00_1.dir/build

CMakeFiles/Init00_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Init00_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Init00_1.dir/clean

CMakeFiles/Init00_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1 D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1 D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00_1\cmake-build-debug\CMakeFiles\Init00_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Init00_1.dir/depend

