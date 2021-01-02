cmake_minimum_required(VERSION 3.10)

project(
  FindThis
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(cmake/ft_generate_header.cmake)

add_subdirectory(ft_bin)
add_subdirectory(ft_lib)
