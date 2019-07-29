cmake_minimum_required(VERSION 3.14)
project(tree C)

set(CMAKE_C_STANDARD 11)


        #下面的是正常的
#aux_source_directory(. DIR_SRCS)
#add_subdirectory(include)
#
#add_executable(Twenty ${DIR_SRCS})
#
#target_link_libraries(Twenty kumiko)


add_subdirectory(include)

add_executable(21 21.c)
add_executable(142 142.c)

target_link_libraries(21 kumiko)
target_link_libraries(142 kumiko)