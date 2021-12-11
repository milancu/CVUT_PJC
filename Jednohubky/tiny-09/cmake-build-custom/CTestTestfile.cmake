# CMake generated Testfile for 
# Source directory: D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09
# Build directory: D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/cmake-build-custom
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(all "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/cmake-build-custom/Debug/tests.exe")
  set_tests_properties(all PROPERTIES  _BACKTRACE_TRIPLES "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;32;add_test;D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(all "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/cmake-build-custom/Release/tests.exe")
  set_tests_properties(all PROPERTIES  _BACKTRACE_TRIPLES "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;32;add_test;D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(all "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/cmake-build-custom/MinSizeRel/tests.exe")
  set_tests_properties(all PROPERTIES  _BACKTRACE_TRIPLES "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;32;add_test;D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(all "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/cmake-build-custom/RelWithDebInfo/tests.exe")
  set_tests_properties(all PROPERTIES  _BACKTRACE_TRIPLES "D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;32;add_test;D:/Vysoka_Skola/3.Semestr/PJC/Projekty/b211_bd6b36pjc/Jednohubky/tiny-09/CMakeLists.txt;0;")
else()
  add_test(all NOT_AVAILABLE)
endif()
