#ifndef PROJECT_02_STATION_H
#define PROJECT_02_STATION_H

#include "structures.h"
#include "../util/buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

STATION *createStation(char *city_name, char *station_name, int platform_capacity, int depot_capacity);
char *createCityStationAbbreviation(STATION *station);
char *getCityName();
char *getStationName();

#endif //PROJECT_02_STATION_H
