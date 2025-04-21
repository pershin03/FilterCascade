cmake_minimum_required(VERSION 3.31)
project(myProjectNIR)

set(CMAKE_CXX_STANDARD 20)

add_executable(myProjectNIR main.cpp
        filter.h
        signal_processing.h)
