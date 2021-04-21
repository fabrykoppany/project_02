//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_TIME_BUSES_H
#define PROJECT_02_TIME_BUSES_H

#include "buses.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * TIME data structure
 * full_time - "hour" converted into minutes + "minutes"
 * time_str - time shown in digital form (HH:MM)
 */
typedef struct{
    int hour, minute, full_time;
    char time_str[5];
}TIME;

#endif //PROJECT_02_TIME_BUSES_H
