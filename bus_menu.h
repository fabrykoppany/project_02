//
// Created by koppa on 2021. 04. 23..
//

#ifndef PROJECT_02_BUS_MENU_H
#define PROJECT_02_BUS_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "structures.h"
#include "buffer.h"
#include "buses.h"
#include "bst_buses.h"
#include "queue_buses.h"
#include "station.h"
#include "database.h"

void clearScreen();
void mainMenu();
void stationMenu();
void loadStationMenu();
void createStationMenu();
void pressKeyToContinue(STATION *station);
void busMenu(STATION *station);
int takeAnswer();

#endif //PROJECT_02_BUS_MENU_H
