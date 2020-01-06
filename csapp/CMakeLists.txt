cmake_minimum_required(VERSION 3.14)
project(csapp)

set(CMAKE_CXX_STANDARD 14)
add_link_options(-pthread)

#add_executable(csapp10-6 10-6.cpp csapp.h csapp.c)
add_executable(csapp10-7 csapp.c csapp.h 10-7.c)
#add_executable(csapp10-8 10-8.cpp csapp.h csapp.c)
#add_executable(csapp10-9 10-9.cpp csapp.h csapp.c)