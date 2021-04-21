//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_TIME_BUSES_H
#define PROJECT_02_TIME_BUSES_H

/*
 * TIME data structure
 * full_time - "hour" converted into minutes + "minute"
 * time_str - time shown in digital form (HH:MM)
 */
typedef struct{
    int hour, minute, full_time;
    char time_str[6];
}TIME;

#include "buses.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

TIME createTime(int hour, int minute);
int convertHMToFT(int hour, int minute);
void convertFTToHM(int full_time, int *hour, int *minute);
char* convertHMToStr(int hour, int minute);
void convertStrToHM(char *time_str, int *hour, int *minute);
bool isHour(int hour);
bool isMinute(int minute);
bool isTime(int hour, int minute);
bool possibleTime(const char *time);

#endif //PROJECT_02_TIME_BUSES_H
