#ifndef PROJECT_02_BUS_MENU_H
#define PROJECT_02_BUS_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "../model/structures.h"
#include "../util/buffer.h"
#include "../model/buses.h"
#include "../data/bst_buses.h"
#include "../data/queue_buses.h"
#include "../model/station.h"
#include "../db/database.h"

void clearScreen();
void mainMenu();
void stationMenu();
void loadStationMenu();
void createStationMenu();
void pressKeyToContinue(STATION *station);
void busMenu(STATION *station);
int takeAnswer();

#endif //PROJECT_02_BUS_MENU_H
