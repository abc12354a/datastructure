cmake_minimum_required(VERSION 3.8)
project(linkedlist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp linkedlist.cpp linkedlist.h)
add_executable(linkedlist ${SOURCE_FILES})