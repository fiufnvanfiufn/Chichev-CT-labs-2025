cmake_minimum_required(VERSION 3.23)

set(project "ourmath")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        ourmath.cpp)

set(${project}_HEADERS
        ourmath.hpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
