cmake_minimum_required(VERSION 3.20)

project(debug_macros)

set(include_dir "${PROJECT_SOURCE_DIR}/src/include")

add_library(debug_macros INTERFACE)

target_include_directories(debug_macros INTERFACE "${include_dir}")

add_executable(debug_macros_simple_test ${CMAKE_SOURCE_DIR}/src/simple_test.cpp)

target_link_libraries(debug_macros_simple_test debug_macros)