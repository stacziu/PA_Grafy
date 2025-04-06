cmake_minimum_required(VERSION 3.28)
project(A2)

set(CMAKE_CXX_STANDARD 17)

add_executable(A2 main.cpp
        graph.h
        graphMatrix.cpp
        graphMatrix.h
        graphList.cpp
        graphList.h)
