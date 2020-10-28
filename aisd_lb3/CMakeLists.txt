cmake_minimum_required(VERSION 3.17)
project(aisd_lb3)

set(CMAKE_CXX_STANDARD 14)

add_executable(aisd_lb3 main.cpp Node.cpp Node.h Tree.h Tree.cpp structs.h InOut.cpp InOut.h)