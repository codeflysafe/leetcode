cmake_minimum_required(VERSION 3.19)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include)

add_executable(leetcode leetcode/310_minimum_height_trees.cpp)