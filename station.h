//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_STATION_H
#define PROJECT_02_STATION_H

#include "buses.h"
#include "bst_buses.h"
#include "queue_buses.h"
#include "buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * STATION data structure
 * root - binary search tree
 * first - dynamic queue
 * city - name of the city where the station is
 * name - name of the station itself
 * also stores both the capacity of its platform and depot
 */
typedef struct{
    BST_Node *root;
    queueNode *first;
    char *city, *name, *abbreviation;
    int platform_capacity, depot_capacity;
}STATION;

STATION createStation(const char *city_name, const char *station_name, int platfrom_capacity, int depot_capacity);
char *createCityStationAbbreviation(STATION station);
char *getCityName();
char *getStationName();

#endif //PROJECT_02_STATION_H
