cmake_minimum_required(VERSION 3.8)
project(lesson01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp tree.cpp tree.h stack.cpp stack.h)
add_executable(lesson01 ${SOURCE_FILES})