cmake_minimum_required(VERSION 3.17)
project(mipt_flat_2020_practice1)

set(MAIN_SOURCE src/main.cpp)

include_directories(includes/constants)
include_directories(includes/checkers)
add_subdirectory(includes/checkers)
include_directories(includes/regular_expr)
add_subdirectory(includes/regular_expr)

add_executable(analyse_reg_exp ${MAIN_SOURCE})

target_link_libraries(analyse_reg_exp RegExp)
target_link_libraries(analyse_reg_exp Checkers)