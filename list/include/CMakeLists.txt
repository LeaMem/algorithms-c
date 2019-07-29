cmake_minimum_required(VERSION 3.14)
project(tree C)

set(CMAKE_C_STANDARD 11)



aux_source_directory(. listSource)

add_library(kumiko ${listSource})
