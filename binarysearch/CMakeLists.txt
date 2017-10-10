cmake_minimum_required(VERSION 3.8)
project(binarysearch)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp bstree.cpp bstree.h)
add_executable(binarysearch ${SOURCE_FILES})