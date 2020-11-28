cmake_minimum_required(VERSION 3.10.0)


set(CMAKE_CXX_STANDARD 14)

project(salut_cpp)

include_directories(${CMAKE_SOURCE_DIR})


set(SRCS)


# add_library(salutcpp ${SRCS})

add_executable(test main.cpp)

# target_link_libraries(test salutcpp)