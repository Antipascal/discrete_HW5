cmake_minimum_required(VERSION 3.16)
project(igraph_test)

find_package(igraph REQUIRED)

add_executable(igraph_test stable_set.cpp)
target_link_libraries(igraph_test PUBLIC igraph::igraph)