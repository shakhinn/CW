cmake_minimum_required(VERSION 3.17)
project(AISD_lb2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AISD_lb2 main.cpp lisp.h lisp.cpp InOut.h InOut.cpp structs.h)