cmake_minimum_required(VERSION 3.8)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp matrix.cpp matrix.h)
add_executable(Matrix ${SOURCE_FILES})