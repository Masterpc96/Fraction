cmake_minimum_required(VERSION 3.8)
project(fraction)
set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp source/Fraction.cpp headers/Fraction.h headers/MyStack.h headers/OnpCalculator.cpp headers/OnpCalculator.h)
add_executable(fraction ${SOURCE_FILES})


set(BOOST_ROOT "/usr/local/Cellar/boost/1.66.0")
find_package(Boost 1.66.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()