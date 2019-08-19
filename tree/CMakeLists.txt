cmake_minimum_required(VERSION 3.14)
project(tree C)

set(CMAKE_C_STANDARD 11)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

#aux_source_directory(. treeSource)

add_subdirectory(include)

add_executable(501 501.c)
add_executable(107 107.c)
add_executable(110 110.c)
add_executable(111 111.c)
add_executable(653 653.c)
add_executable(543 543.c)
add_executable(112 112.c)
add_executable(404 404.c)
add_executable(226 226.c)
add_executable(993 993.c)
add_executable(235 235.c)
add_executable(257 257.c)
add_executable(687 687.c)

target_link_libraries(257 kazusa)