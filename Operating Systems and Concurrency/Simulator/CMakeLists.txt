cmake_minimum_required(VERSION 3.0.2)
project (simulator)
if(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(simulator main.cpp Fifo.h Fifo.cpp)
