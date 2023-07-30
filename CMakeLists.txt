cmake_minimum_required(VERSION 3.24)

project(IntroductionToAlgorithms VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

include_directories(lib/include)

add_executable(sorter src/sort_algs.cpp lib/src/chap2.cpp lib/src/chap6.cpp)

add_executable(multiplier src/multiply_matrices.cpp lib/src/chap4.cpp lib/src/chap2.cpp)

add_executable(data_structures src/data_structures.cpp lib/src/chap10.cpp lib/src/chap2.cpp)

add_executable(graphs_tester src/graphs.cpp lib/src/chap20.cpp)

add_executable(bst_tester src/bst_tester.cpp lib/src/chap12.cpp)

add_executable(dynamic_programming src/dynamic_programming.cpp lib/src/chap14.cpp lib/src/chap20.cpp)

add_executable(dp-exercices src/dynamic_programming_exercices.cpp lib/src/chap14.cpp lib/src/chap20.cpp)

add_executable(greedy_algorithms src/greedy_algorithms.cpp lib/src/chap15.cpp)