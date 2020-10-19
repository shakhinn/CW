cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(OOP main.cpp Field.cpp Field.h Cell.cpp Cell.h Player.cpp Player.h Object.cpp Object.h Point.h Controller.cpp Controller.h View.cpp View.h)

target_link_libraries(OOP sfml-graphics sfml-audio)