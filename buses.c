//
// Created by koppa on 2021. 04. 21..
//

#include "buses.h"

BUS createBus(STATION station, const char *bus_name, TIME departure){
    BUS bus;

    bus.name = allocateMemory(20);
    strcpy(bus.name, station.abbreviation);
    strcat(bus.name, bus_name);
    reallocateMemory(&bus.name);
    bus.departure_time = departure;

    return bus;
}