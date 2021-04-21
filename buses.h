//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_BUSES_H
#define PROJECT_02_BUSES_H

#include "time_buses.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * BUS data structure
 * name - stores the bus' name (to be generated from station details)
 * departure_time - departure time of bus in all forms
 */
typedef struct{
    char name[20];
    TIME departure_time;
}BUS;

#endif //PROJECT_02_BUSES_H
