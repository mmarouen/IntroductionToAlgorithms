cmake_minimum_required(VERSION 3.24)

project(IntroductionToAlgorithms VERSION 0.0.1)
include(GNUInstallDirs)

add_executable(sorter src/sort_algs.cpp lib/src/chap2.cpp lib/src/chap6.cpp)
target_include_directories(sorter PUBLIC lib/include)

add_executable(multiplier src/multiply_matrices.cpp lib/src/chap4.cpp lib/src/chap2.cpp)
target_include_directories(multiplier PUBLIC lib/include)

add_executable(data_structures src/data_structures.cpp lib/src/chap10.cpp lib/src/chap2.cpp)
target_include_directories(data_structures PUBLIC lib/include)

add_executable(bst_tester src/bst_tester.cpp lib/src/chap12.cpp)
target_include_directories(bst_tester PUBLIC lib/include)
