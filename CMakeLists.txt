cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-g -Wall)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)