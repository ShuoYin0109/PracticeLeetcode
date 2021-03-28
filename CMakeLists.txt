# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp UnionFind.h UnionFind.cpp BinaryTree.h BinaryTree.cpp)