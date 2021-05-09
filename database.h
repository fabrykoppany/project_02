#ifndef PROJECT_02_DATABASE_H
#define PROJECT_02_DATABASE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "file.h"
#include "time_buses.h"
#include "queue_buses.h"
#include "bst_buses.h"
#include "structures.h"

#define GLOBAL_DB_FILENAME "global_db.bin"

typedef struct global_db_t {
    size_t stationCount;
    STATION **stations;
} global_db_t;

global_db_t globalDatabase;

bool loadGlobalDatabase();
bool saveGlobalDatabase();

void freeStations(STATION **stations, size_t n);
bool writeStation(FILE *file, STATION *station);
STATION *loadStation(FILE *file);

bool writeBus(FILE *file, BUS bus);
BUS loadBus(FILE *file);

bool writeTime(FILE *file, TIME time);
TIME loadTime(FILE *file);

bool writePlatform(FILE *file, BST_Node *root);
void inorderWriteBus(FILE *file, BST_Node *root);
BST_Node *loadPlatform(FILE *file);

bool writeDepot(FILE *file, queueNode *root);
int loadDepot(FILE *file, queueNode **first, queueNode **last);

bool addStationToDatabase(STATION *station);

#endif //PROJECT_02_DATABASE_H