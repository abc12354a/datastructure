cmake_minimum_required(VERSION 3.8)
project(Huffman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp huffman.cpp huffman.h)
add_executable(Huffman ${SOURCE_FILES})