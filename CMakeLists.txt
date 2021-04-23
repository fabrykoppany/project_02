cmake_minimum_required(VERSION 3.17)
project(project_02 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_02 main.c buses.c buses.h station.c station.h  bst_buses.c bst_buses.h queue_buses.c queue_buses.h time_buses.c time_buses.h buffer.c buffer.h structures.h)