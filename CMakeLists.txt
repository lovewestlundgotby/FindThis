cmake_minimum_required(VERSION 3.10)

project(
  FindThis
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/ft_generate_header.cmake)

add_subdirectory(src)
