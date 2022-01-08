cmake_minimum_required(VERSION 3.21)
project(vypocet_determinantu)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(
        vypocet_determinantu
        main.cpp
)

add_executable(
        tests
        tests/test.cpp
        tests/tests-main.cpp
        tests/catch.hpp
        )
enable_testing()
add_test(NAME tests COMMAND tests)
