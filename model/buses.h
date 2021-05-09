#ifndef PROJECT_02_BUSES_H
#define PROJECT_02_BUSES_H

#include "time_buses.h"
#include "structures.h"
#include "../util/buffer.h"

#include <stdio.h>
#include <stdlib.h>

BUS createBus(STATION station, const char *bus_name, TIME departure);

#endif //PROJECT_02_BUSES_H
