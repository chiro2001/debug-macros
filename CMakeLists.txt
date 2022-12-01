cmake_minimum_required(VERSION 3.20)

project(debug_macros)

include_directories("${PROJECT_SOURCE_DIR}/src/include")

add_executable(debug_macros_simple_test ${CMAKE_SOURCE_DIR}/src/simple_test.cpp)