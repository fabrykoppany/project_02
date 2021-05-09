#ifndef PROJECT_02_QUEUE_BUSES_H
#define PROJECT_02_QUEUE_BUSES_H

#include "../model/structures.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

queueNode *createQ();
bool isEmptyQ(queueNode *first, queueNode *last);
void addBus(queueNode **first, queueNode **last, BUS bus);
void enter(STATION *station, queueNode **first, queueNode **last, BUS bus);
BUS leave(STATION *station, queueNode **first, queueNode *last);
void listQ(queueNode *first, queueNode *last);
bool findQ(queueNode *first, queueNode *last, BUS key);
int getSizeQ(queueNode *first);

#endif //PROJECT_02_QUEUE_BUSES_H
