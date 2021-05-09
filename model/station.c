#include "station.h"

STATION *createStation(char *city_name, char *station_name, int platform_capacity, int depot_capacity) {
    STATION *station = (STATION *) calloc(1, sizeof(STATION));

    if (station == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    station->platform_capacity = platform_capacity;
    station->depot_capacity = depot_capacity;
    station->name = station_name;
    station->city = city_name;
    station->abbreviation = createCityStationAbbreviation(station);

    return station;
}

char *createCityStationAbbreviation(STATION *station) {
    char *abbr = allocateMemory(5);

    abbr[0] = station->city[0];
    abbr[1] = station->city[1];
    abbr[2] = station->name[0];
    abbr[3] = station->name[1];
    abbr[4] = '\0';

    for (int i = 0; i < strlen(abbr); ++i) {
        abbr[i] = (char) toupper(abbr[i]);
    }

    return abbr;
}

char *getCityName() {
    return getBuffer();
}

char *getStationName() {
    return getBuffer();
}