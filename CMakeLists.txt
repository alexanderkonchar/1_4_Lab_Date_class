cmake_minimum_required(VERSION 3.24)
project(1_4_Lab_Date_class)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(1_4_Lab_Date_class
        DateTesting.cpp Date.cpp Date.h)
