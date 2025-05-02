# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project("CodeEditor")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the include directories for Scintilla
include_directories(${CMAKE_SOURCE_DIR}/scintilla/include)

# Add the source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB_RECURSE SOURCES_RECURSED "src/*/*.cpp")
list(APPEND SOURCES ${SOURCES_RECURSED})

# Add souces
add_executable(${SOURCES}, ${PROJECT_NAME})