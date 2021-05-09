#include "database.h"

bool loadGlobalDatabase() {
    // First, free the stations if they have been allocated previously
    if (globalDatabase.stations) {
        freeStations(globalDatabase.stations, globalDatabase.stationCount);
    }

    FILE *file = fopen(GLOBAL_DB_FILENAME, "rb");

    if (file == NULL) {
        // Database does not exist, let's create it.
        globalDatabase.stationCount = 0;
        globalDatabase.stations = NULL;
        return saveGlobalDatabase() && loadGlobalDatabase();
    }

    fread(&(globalDatabase.stationCount), sizeof(size_t), 1, file);

    if (globalDatabase.stationCount == 0) {
        globalDatabase.stations = NULL;
        fclose(file);
        return true;
    }

    globalDatabase.stations = (STATION **) malloc(globalDatabase.stationCount * sizeof(STATION *));

    if (globalDatabase.stations == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    for (size_t i = 0; i < globalDatabase.stationCount; ++i) {
        STATION *station = loadStation(file);

        if (station == NULL) {
            printf("Failed to load station...\n");
            fclose(file);
            return false;
        }

        globalDatabase.stations[i] = station;
    }

    fclose(file);
    return true;
}

bool saveGlobalDatabase() {
    FILE *file = fopen(GLOBAL_DB_FILENAME, "wb");

    if (file == NULL) {
        printf("Could not open global database for writing!\n");
        return false;
    }

    fwrite(&(globalDatabase.stationCount), sizeof(size_t), 1, file);

    for (size_t i = 0; i < globalDatabase.stationCount; ++i) {
        writeStation(file, globalDatabase.stations[i]);
    }

    fclose(file);
    return true;
}

void freeStations(STATION **stations, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        free(stations[i]);
    }

    free(stations);
}

bool writeStation(FILE *file, STATION *station) {
    writeStringToFile(file, station->city);
    writeStringToFile(file, station->name);
    writeStringToFile(file, station->abbreviation);
    fwrite(&(station->platform_capacity), sizeof(int), 1, file);
    fwrite(&(station->depot_capacity), sizeof(int), 1, file);

    writePlatform(file, station->root);
    writeDepot(file, station->first);

    return true;
}

STATION *loadStation(FILE *file) {
    STATION *station = (STATION *) calloc(1, sizeof(STATION));

    if (station == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    readStringToField(file, &(station->city));
    readStringToField(file, &(station->name));
    readStringToField(file, &(station->abbreviation));
    fread(&(station->platform_capacity), sizeof(int), 1, file);
    fread(&(station->depot_capacity), sizeof(int), 1, file);

    station->root = loadPlatform(file);
    station->platform_size = sizeBST(station->root);
    station->depot_size = loadDepot(file, &(station->first), &(station->last));

    return station;
}

bool writeBus(FILE *file, BUS bus) {
    writeStringToFile(file, bus.name);
    return writeTime(file, bus.departure_time);
}

BUS loadBus(FILE *file) {
    BUS bus;

    readStringToField(file, &(bus.name));
    bus.departure_time = loadTime(file);
    return bus;
}

bool writeTime(FILE *file, TIME time) {
    fwrite(&(time.hour), sizeof(int), 1, file);
    fwrite(&(time.minute), sizeof(int), 1, file);
    return true;
}

TIME loadTime(FILE *file) {
    int hour, minute;
    fread(&hour, sizeof(int), 1, file);
    fread(&minute, sizeof(int), 1, file);
    return createTime(hour, minute);
}

bool writePlatform(FILE *file, BST_Node *root) {
    int size = sizeBST(root);
    fwrite(&size, sizeof(int), 1, file);

    inorderWriteBus(file, root);
    return true;
}

void inorderWriteBus(FILE *file, BST_Node *root) {
    if (root == NULL) {
        return;
    }

    inorderWriteBus(file, root->left);
    writeBus(file, root->bus_data);
    inorderWriteBus(file, root->right);
}

BST_Node *loadPlatform(FILE *file) {
    BST_Node *root = NULL;

    int size;
    fread(&size, sizeof(int), 1, file);

    for (int i = 0; i < size; ++i) {
        addBSTBus(&root, loadBus(file));
    }

    return root;
}

bool writeDepot(FILE *file, queueNode *root) {
    int size = getSizeQ(root);
    queueNode *aux = root;

    fwrite(&size, sizeof(int), 1, file);

    while (aux != NULL) {
        if (!writeBus(file, aux->bus_data)) {
            return false;
        }

        aux = aux->next;
    }

    return true;
}

int loadDepot(FILE *file, queueNode **first, queueNode **last) {
    (*first) = NULL;
    (*last) = NULL;

    int size;
    fread(&size, sizeof(int), 1, file);

    for (int i = 0; i < size; ++i) {
        addBus(first, last, loadBus(file));
    }

    return size;
}

bool addStationToDatabase(STATION *station) {
    if (globalDatabase.stationCount == 0) {
        // We don't have any stations yet, so create a new array.
        globalDatabase.stations = (STATION **) malloc(sizeof(STATION *));
    } else {
        // Add one more capacity to this array.
        globalDatabase.stations = (STATION **) realloc(globalDatabase.stations, (globalDatabase.stationCount + 1) * sizeof(STATION *));
    }

    if (globalDatabase.stations == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    // Add our new station to the station map.
    globalDatabase.stations[globalDatabase.stationCount++] = station;
    saveGlobalDatabase();
    return true;
}