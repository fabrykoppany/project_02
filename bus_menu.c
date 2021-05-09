//
// Created by koppa on 2021. 04. 23..
//

#include "bus_menu.h"

void clearScreen(){
    system("cls");
}

int takeAnswer(){
    int choice = 0;
    char *answer = allocateMemory(20);

    printf("Waiting for an answer... ");
    scanf("%s", answer);

    if (onlyDigitsStr(answer)){
        choice = atoi(answer);
    }
    else {
        choice = -1;
    }

    free(answer);

    return choice;
}

void mainMenu(){
    clearScreen();

    printf("Welcome to the SapiBus bus management tool!\n\n");
    printf("You can do the following: \n\n");
    printf("|->1. stations - Access your existing stations or add a new station to the database\n");
    printf("\n###########################\n");
    printf("\n|->0. EXIT - exit the application\n\n");

    int choice = takeAnswer();

    switch (choice) {
        case 1: stationMenu(); choice = 0; break;
        case 0: exit(1);
        default: printf("No such answer. Please try again."); getch(); mainMenu();
    }
}

void stationMenu(){
    clearScreen();

    printf("####Station Menu####\n\n");
    printf("You can do the following:\n\n");
    printf("|->1. load station - Access an already existing bus in the database\n");
    printf("|->2. create station - Create and add a brand new station to the database\n");
    printf("\n###########################\n");
    printf("\n|->0. EXIT - exit the application\n\n");

    int choice = takeAnswer();

    switch (choice) {
        case 1: loadStationMenu(); break;
        case 2: createStationMenu(); choice = 0; break;
        case 0: exit(1);
        default: printf("No such answer. Please try again."); getch(); stationMenu();
    }
}

void loadStationMenu() {
    clearScreen();

    printf("####Station Menu####\n\n");
    printf("You may head to the following stations:\n");

    for (size_t i = 0; i < globalDatabase.stationCount; ++i) {
        STATION *station = globalDatabase.stations[i];
        printf("|->%d. %s (%s) [%s]\n", i + 1, station->name, station->city, station->abbreviation);
    }

    printf("\n###########################\n");
    printf("\n|->0. BACK - head back to previous menu\n\n");

    int choice = takeAnswer();

    if (choice == 0 || choice > globalDatabase.stationCount) {
        stationMenu();
        return;
    }

    STATION *station = globalDatabase.stations[choice - 1];
    busMenu(station);
}

void createStationMenu(){
    clearScreen();

    char *city_name, *station_name;
    int p_cap = -1;
    int d_cap = -1;

    printf("####Create a new station####\n\n");

    printf("The name of the city you want to register your new station: ");
    city_name = getCityName();

    printf("The name of the station itself: ");
    station_name = getStationName();

    while (p_cap < 0) {
        printf("The station's platform's capacity: ");
        scanf("%i", &p_cap);
    }

    while (d_cap < 0) {
        printf("The station's depot's capacity: ");
        scanf("%i", &d_cap);
    }

    STATION *station = createStation(city_name, station_name, p_cap, d_cap);

    if (station == NULL) {
        // Memory allocation failure.
        return;
    }

    addStationToDatabase(station);

    printf("\nThe city in which your station is located in: %s\n", station->city);
    printf("Your station's name: %s\n", station->name);
    printf("The station's platform's and depot's capacity: %i - %i\n", station->platform_capacity, station->depot_capacity);
    printf("The abbreviation your buses are going to take: %s\n\n", station->abbreviation);

    printf("If you're happy with the changes, press a key to jump to the bus management tool..."); getch();

    free(city_name); free(station_name);

    busMenu(station);
}

void pressKeyToContinue(STATION *station) {
    printf("\nPress a key to continue...");
    getch();
    busMenu(station);
}

void busMenu(STATION *station){
    clearScreen();

    printf("####Bus management####\n\n");
    printf("\tNumber of buses on platform: %i\n", station->platform_size);
    printf("\tNumber of buses in depot: %i\n\n", station->depot_size);
    printf("You can do the following: \n\n");
    printf("|->1. Add a bus directly on the platform. If it doesn't fit in, we'll add it to the depot.\n");
    printf("|->2. Add a bus to the depot.\n");
    printf("|->3. Release a bus from the platform.\n");
    printf("|->4. Release every bus from the platform.\n");
    printf("|->5. Take out as many buses out from depot and onto the platform as possible.\n");
    printf("|->6. List the buses that are currently on the platform.\n");
    printf("|->7. List the buses that are currently in the depot.\n");
    printf("\n###########################\n");
    printf("\n|->0. EXIT - head back to main menu\n\n");

    int choice = takeAnswer();

    switch (choice) {
        case 1:
            printf("Name of the bus: ");
            char *name = getBuffer();

            int hour, minute;
            printf("Time of the bus' departure (HH MM): ");
            scanf("%i%i", &hour, &minute);

            BUS bus = createBus(*station, name, createTime(hour, minute));

            if (busNameTakenBST(station->root, bus.name)){
                printf("Bus name is already taken. Please try again.\n");

                printf("\nPress a key to continue...");
                getch();

                busMenu(station);
            }

            if (findQ(station->first, station->last, bus)){
                printf("Bus name is already taken or another bus leaves at the same time. Please try again.\n");

                printf("\nPress a key to continue...");
                getch();

                busMenu(station);
            }

            insert(station, &station->root, bus);
            saveGlobalDatabase();

            free(name);
            pressKeyToContinue(station);
            break;
        case 2:
            printf("Name of the bus: ");
            name = getBuffer();

            printf("Time of the bus' departure (HH:MM): ");
            scanf("%i%i", &hour, &minute);

            bus = createBus(*station, name, createTime(hour, minute));

            if (busNameTakenBST(station->root, bus.name)){
                printf("Bus name is already taken. Please try again.\n");

                printf("\nPress a key to continue...");
                getch();

                busMenu(station);
            }

            if (findBST(station->root, bus)){
                printf("No two buses can leave at the same time. Please try again.\n");

                printf("\nPress a key to continue...");
                getch();

                busMenu(station);
            }

            enter(station, &station->first, &station->last, bus);
            saveGlobalDatabase();

            free(name);
            pressKeyToContinue(station);
            break;
        case 3:
            printf("The next bus in line will leave the platform.\n");

            if (minimum(station->root) == NULL) {
                printf("No bus yet on the platform.\n");
            } else {
                BUS leaving = minimum(station->root)->bus_data;
                station->root = delete(station, station->root, leaving);
                saveGlobalDatabase();
                printf("%s has left at %s.\n", leaving.name, leaving.departure_time.time_str);
            }

            pressKeyToContinue(station);
        case 4:
            station->root = emptyPlatform(station, station->root);
            saveGlobalDatabase();
            printf("Every bus has left the platform.\n");
            pressKeyToContinue(station);
            break;
        case 5:
            takeBusesFromDepot(station, &station->root);
            saveGlobalDatabase();
            busMenu(station);
            break;
        case 6:
            if (isEmptyBST(station->root)){
                printf("Platform is empty.\n\nPress a key to continue...");
                getch();
                busMenu(station);
            }

            listBST(station->root);
            pressKeyToContinue(station);
            break;
        case 7:
            listQ(station->first, station->last);
            pressKeyToContinue(station);
            break;
        case 0: mainMenu(); break;
        default: printf("No such answer. Please try again."); getch(); busMenu(station);
    }
}