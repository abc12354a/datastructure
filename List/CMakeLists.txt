cmake_minimum_required(VERSION 3.8)
project(List)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp list.cpp list.h)
add_executable(List ${SOURCE_FILES})