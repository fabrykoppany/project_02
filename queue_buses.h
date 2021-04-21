//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_QUEUE_BUSES_H
#define PROJECT_02_QUEUE_BUSES_H

#include "buses.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Dynamic queue - depot
 * queue's data is of type BUS
 * first enters into depot, first leaves (FIFO)
 * depot has a capacity
 */
typedef struct queueNode{
    BUS bus_data;
    int index;
    struct queueNode *next;
}queueNode;

#endif //PROJECT_02_QUEUE_BUSES_H
