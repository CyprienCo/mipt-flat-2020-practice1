cmake_minimum_required(VERSION 3.10)
project(mipt-flat-2020-practice1)

set(SOURCE_LIB reg_exp.cpp)
add_library(RegExp SHARED ${SOURCE_LIB})