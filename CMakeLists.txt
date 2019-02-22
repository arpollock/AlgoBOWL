cmake_minimum_required(VERSION 3.8)
project(AlgoBOWL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SolutionAlgorithm.cpp SolutionAlgorithm.h)
add_executable(AlgoBOWL ${SOURCE_FILES})