# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\phuon\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.75\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\phuon\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.75\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00\cmake-build-debug

# Utility rule file for NightlySubmit.

# Include any custom commands dependencies for this target.
include CMakeFiles\NightlySubmit.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\NightlySubmit.dir\progress.make

CMakeFiles\NightlySubmit:
	C:\Users\phuon\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.75\bin\cmake\win\bin\ctest.exe -D NightlySubmit

NightlySubmit: CMakeFiles\NightlySubmit
NightlySubmit: CMakeFiles\NightlySubmit.dir\build.make
.PHONY : NightlySubmit

# Rule to build all files generated by this target.
CMakeFiles\NightlySubmit.dir\build: NightlySubmit
.PHONY : CMakeFiles\NightlySubmit.dir\build

CMakeFiles\NightlySubmit.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NightlySubmit.dir\cmake_clean.cmake
.PHONY : CMakeFiles\NightlySubmit.dir\clean

CMakeFiles\NightlySubmit.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00 D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00 D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00\cmake-build-debug D:\Vysoka_Skola\3.Semestr\PJC\Projekty\b211_bd6b36pjc\Jednohubky\Init00\cmake-build-debug\CMakeFiles\NightlySubmit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\NightlySubmit.dir\depend

