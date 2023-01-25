cmake_minimum_required (VERSION 3.0.0)

project (helloworld)

# the lines below define variables 
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (helloworld ${source_files})
