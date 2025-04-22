cmake_minimum_required(VERSION 3.31)
project(FilterCascade)

set(CMAKE_CXX_STANDARD 20)

add_executable(FilterCascade main.cpp
        filterCIC.h
        signal_processing.h
        signal_processing.cpp
        filterCIC.cpp
        filterFIR.h
        filterFIR.cpp)
