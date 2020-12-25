cmake_minimum_required(VERSION 3.10)
project(mipt-flat-2020-practice1)

set(SOURCE_LIB checkers.cpp)
add_library(Checkers SHARED ${SOURCE_LIB})