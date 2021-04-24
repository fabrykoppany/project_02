//
// Created by koppa on 2021. 04. 21..
//

#include "time_buses.h"

TIME createTime(int hour, int minute) {
    TIME time;

    time.hour = hour;
    time.minute = minute;
    time.full_time = convertHMToFT(hour, minute);
    strcpy(time.time_str, convertHMToStr(hour, minute));

    return time;
}

int convertHMToFT(int hour, int minute){
    return hour * 60 + minute;
}

void convertFTToHM(int full_time, int *hour, int *minute){
    *hour = full_time / 60;
    *minute = full_time % 60;
}

char* convertHMToStr(int hour, int minute){
    if (isTime(hour, minute)) {
        char *time, *hour_str, *minute_str;

        time = (char *) calloc(6, sizeof(char));
        hour_str = (char *) calloc(2, sizeof(char));
        minute_str = (char *) calloc(2, sizeof(char));

        if (time == NULL || hour_str == NULL || minute_str == NULL) {
            printf("Error allocating memory!!!\n");
            exit(-1);
        }

        sprintf(hour_str, "%i", hour);
        sprintf(minute_str, "%i", minute);
        if (minute == 0){
            strcat(minute_str, "0");
        }

        strcpy(time, hour_str);
        strcat(time, ":");
        strcat(time, minute_str);
        strcat(time, "\0");

        free(hour_str);
        free(minute_str);

        return time;
    } else{
        printf("The given hour / minute format isn't a valid time.\n");
        return NULL;
    }
}

void convertStrToHM(char *time_str, int *hour, int *minute){
    if (possibleTime(time_str)) {
        char *hour_str, *minute_str;

        hour_str = (char *) calloc(2, sizeof(char));
        minute_str = (char *) calloc(2, sizeof(char));

        if (hour_str == NULL || minute_str == NULL) {
            printf("Error allocating memory!!!\n");
            exit(-1);
        }

        hour_str[0] = time_str[0];
        hour_str[1] = time_str[1];
        minute_str[0] = time_str[3];
        minute_str[1] = time_str[4];

        int hour_test = atoi(hour_str), minute_test = atoi(minute_str);

        if (isTime(hour_test, minute_test)) {
            *hour = atoi(hour_str);
            *minute = atoi(minute_str);
        }

        free(hour_str);
        free(minute_str);
    } else{
        printf("The given hour / minute format isn't a valid time.\n");
        return;
    }
}

bool isHour(int hour){
    if (0 <= hour && hour <= 23){
        return true;
    }

    return false;
}

bool isMinute(int minute){
    if (0 <= minute && minute <= 59){
        return true;
    }

    return false;
}

bool isTime(int hour, int minute){
    if (isHour(hour) && isMinute(minute)){
        return true;
    }

    return false;
}

bool possibleTime(const char *time){
    if (strlen(time) == 5 && time[2] == ':'){
        return true;
    }

    return false;
}