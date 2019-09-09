cmake_minimum_required(VERSION 3.14)
project(trl)

set(CMAKE_CXX_STANDARD 17)
include_directories(trl)
add_executable(trl main.cpp trl/map_range.h trl/basic_range_v2.h)