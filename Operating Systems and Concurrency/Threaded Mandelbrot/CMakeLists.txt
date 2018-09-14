cmake_minimum_required(VERSION 3.0.2)
project (theard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(theard main.cpp)
