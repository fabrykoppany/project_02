#ifndef PROJECT_02_TIME_BUSES_H
#define PROJECT_02_TIME_BUSES_H

#include "structures.h"

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
