cmake_minimum_required(VERSION 3.24)

project(introductionToAlgorithms VERSION 0.0.1)
include(GNUInstallDirs)

add_executable(sorter src/sort_algs.cpp lib/src/chap2.cpp)
target_include_directories(sorter PUBLIC lib/include)

add_executable(multiplier src/multiply_matrices.cpp lib/src/chap4.cpp lib/src/chap2.cpp)
target_include_directories(multiplier PUBLIC lib/include)