cmake_minimum_required(VERSION 3.17)
project(project_02 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_02 main.c model/buses.c model/buses.h model/station.c model/station.h data/bst_buses.c data/bst_buses.h data/queue_buses.c data/queue_buses.h model/time_buses.c model/time_buses.h util/buffer.c util/buffer.h model/structures.h menu/bus_menu.c menu/bus_menu.h util/file.c util/file.h db/database.c db/database.h)