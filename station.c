//
// Created by koppa on 2021. 04. 21..
//

#include "station.h"

STATION createStation(const char *city_name, const char *station_name, int platfrom_capacity, int depot_capacity){
    STATION station;

    station.platform_capacity = platfrom_capacity;
    station.depot_capacity = depot_capacity;
    station.name = allocateMemory(20);
    strcpy(station.name, station_name);
    station.city = allocateMemory(20);
    strcpy(station.city, city_name);
    station.abbreviation = allocateMemory(5);
    strcpy(station.abbreviation, createCityStationAbbreviation(station));
    station.root = NULL;
    station.first = NULL;
    station.platform_size = 0;
    station.depot_size = 0;

    return station;
}

char *createCityStationAbbreviation(STATION station){
    char *abbr = allocateMemory(5);

    abbr[0] = station.city[0];
    abbr[1] = station.city[1];
    abbr[2] = station.name[0];
    abbr[3] = station.name[1];
    abbr[4] = '\0';

    for (int i = 0; i < strlen(abbr); ++i){
        abbr[i] = (char) toupper(abbr[i]);
    }

    return abbr;
}

char *getCityName(){
    return getBuffer();
}

char *getStationName(){
    return getBuffer();
}