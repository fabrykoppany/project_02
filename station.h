//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_STATION_H
#define PROJECT_02_STATION_H

#include "buses.h"
#include "bst_buses.h"
#include "queue_buses.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * STATION data structure
 * root - binary search tree
 * first - dynamic queue
 * city - name of the city where the station is
 * name - name of the station itself
 */
typedef struct{
    BST_Node *root;
    queueNode *first;
    char city[20], name[20];
}STATION;

#endif //PROJECT_02_STATION_H
