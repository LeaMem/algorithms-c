cmake_minimum_required(VERSION 3.14)
project(tree C)

set(CMAKE_C_STANDARD 11)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

#aux_source_directory(. treeSource)


add_executable(501 501.c)
add_executable(107 107.c)
add_executable(110 110.c)
add_executable(111 111.c)
add_executable(653 653.c)