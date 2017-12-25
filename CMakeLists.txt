cmake_minimum_required(VERSION 3.8)
project(fraction)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp source/Fraction.cpp headers/Fraction.h source/MyStack.cpp headers/MyStack.h)
add_executable(fraction ${SOURCE_FILES})