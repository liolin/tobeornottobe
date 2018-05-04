# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(tobeornottobe)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# Compile Debug
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES "*.cpp")
add_executable(tobeornottobe ${SOURCES})
