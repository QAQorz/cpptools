cmake_minimum_required(VERSION 3.14)
project(cpptools)

set(CMAKE_CXX_STANDARD 14)
add_link_options(-pthread)

add_executable(cpptools main.cpp)