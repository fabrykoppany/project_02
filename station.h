//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_STATION_H
#define PROJECT_02_STATION_H

#include "structures.h"
#include "buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

STATION createStation(const char *city_name, const char *station_name, int platfrom_capacity, int depot_capacity);
char *createCityStationAbbreviation(STATION station);
char *getCityName();
char *getStationName();

#endif //PROJECT_02_STATION_H
