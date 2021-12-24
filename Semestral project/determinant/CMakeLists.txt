cmake_minimum_required(VERSION 3.21)
project(determinant)

set(CMAKE_CXX_STANDARD 14)

add_executable(determinant main.cpp matrix.cpp matrix.hpp)
