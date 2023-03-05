cmake_minimum_required(VERSION 3.24)

project(IntroductionToAlgorithms VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

add_executable(sorter src/sort_algs.cpp lib/src/chap2.cpp lib/src/chap6.cpp)
target_include_directories(sorter PUBLIC lib/include)

add_executable(multiplier src/multiply_matrices.cpp lib/src/chap4.cpp lib/src/chap2.cpp)
target_include_directories(multiplier PUBLIC lib/include)

add_executable(data_structures src/data_structures.cpp lib/src/chap10.cpp lib/src/chap2.cpp)
target_include_directories(data_structures PUBLIC lib/include)

add_executable(bst_tester src/bst_tester.cpp lib/src/chap12.cpp)
target_include_directories(bst_tester PUBLIC lib/include)

add_executable(dynamic_programming src/dynamic_programming.cpp lib/src/chap14.cpp)
target_include_directories(dynamic_programming PUBLIC lib/include)

add_executable(dp-exercices src/dynamic_programming_exercices.cpp lib/src/chap14.cpp)
target_include_directories(dp-exercices PUBLIC lib/include)

add_executable(graphs_tester src/graphs.cpp lib/src/chap20.cpp)
target_include_directories(graphs_tester PUBLIC lib/include)

