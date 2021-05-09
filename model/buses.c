#include "buses.h"

BUS createBus(STATION station, const char *bus_name, TIME departure) {
    BUS bus;

    bus.name = allocateMemory(strlen(bus_name) + strlen(station.abbreviation) + 1);
    strcpy(bus.name, station.abbreviation);
    strcat(bus.name, bus_name);
    bus.departure_time = departure;

    return bus;
}