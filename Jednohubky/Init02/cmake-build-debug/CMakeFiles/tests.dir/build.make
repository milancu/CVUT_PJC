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
CMAKE_SOURCE_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/tiny-02.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tiny-02.cpp.obj: ../tiny-02.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/tiny-02.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tests.dir\tiny-02.cpp.obj -c D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tiny-02.cpp

CMakeFiles/tests.dir/tiny-02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tiny-02.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tiny-02.cpp > CMakeFiles\tests.dir\tiny-02.cpp.i

CMakeFiles/tests.dir/tiny-02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tiny-02.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tiny-02.cpp -o CMakeFiles\tests.dir\tiny-02.cpp.s

CMakeFiles/tests.dir/tests-tiny-02.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests-tiny-02.cpp.obj: ../tests-tiny-02.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/tests-tiny-02.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tests.dir\tests-tiny-02.cpp.obj -c D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tests-tiny-02.cpp

CMakeFiles/tests.dir/tests-tiny-02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests-tiny-02.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tests-tiny-02.cpp > CMakeFiles\tests.dir\tests-tiny-02.cpp.i

CMakeFiles/tests.dir/tests-tiny-02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests-tiny-02.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tests-tiny-02.cpp -o CMakeFiles\tests.dir\tests-tiny-02.cpp.s

CMakeFiles/tests.dir/tests-main.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests-main.cpp.obj: ../tests-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/tests-main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tests.dir\tests-main.cpp.obj -c D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tests-main.cpp

CMakeFiles/tests.dir/tests-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests-main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tests-main.cpp > CMakeFiles\tests.dir\tests-main.cpp.i

CMakeFiles/tests.dir/tests-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests-main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\tests-main.cpp -o CMakeFiles\tests.dir\tests-main.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/tiny-02.cpp.obj" \
"CMakeFiles/tests.dir/tests-tiny-02.cpp.obj" \
"CMakeFiles/tests.dir/tests-main.cpp.obj"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests.exe: CMakeFiles/tests.dir/tiny-02.cpp.obj
tests.exe: CMakeFiles/tests.dir/tests-tiny-02.cpp.obj
tests.exe: CMakeFiles/tests.dir/tests-main.cpp.obj
tests.exe: CMakeFiles/tests.dir/build.make
tests.exe: CMakeFiles/tests.dir/linklibs.rsp
tests.exe: CMakeFiles/tests.dir/objects1.rsp
tests.exe: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests.exe
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02 D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02 D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init02\cmake-build-debug\CMakeFiles\tests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

