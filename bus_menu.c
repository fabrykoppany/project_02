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

void mainMenu(STATION *station){
    clearScreen();

    printf("Welcome to the SapiBus bus managment tool!\n\n");
    printf("You can do the following: \n\n");
    printf("|->1. stations - Access your existing stations or add a new station to the database\n");
    printf("\n###########################\n");
    printf("\n|->0. EXIT - exit the application\n\n");

    int choice = takeAnswer();

    switch (choice) {
        case 1: stationMenu(station); choice = 0; break;
        case 0: exit(1);
        default: printf("No such answer. Please try again."); getch(); mainMenu(station);
    }
}

void stationMenu(STATION *station){
    clearScreen();

    printf("####Station Menu####\n\n");
    printf("You can do the following:\n\n");
    printf("|->1. load station - Access an already existing bus in the database\n");
    printf("|->2. create station - Create and add a brande new station to the database\n");
    printf("\n###########################\n");
    printf("\n|->0. EXIT - exit the application\n\n");

    int choice = takeAnswer();

    switch (choice) {
        case 1: choice = 0; break;
        case 2: creatStationMenu(station); choice = 0; break;
        case 0: exit(1);
        default: printf("No such answer. Please try again."); getch(); stationMenu(station);
    }
}

void creatStationMenu(STATION *station){
    clearScreen();

    char *city_name, *station_name;
    int p_cap, d_cap;

    printf("####Create a new station####\n\n");

    printf("The name of the city you want to register your new station: ");
    city_name = getCityName();

    printf("The name of the station itself: ");
    station_name = getStationName();

    printf("The station's platform's capacity: ");
    scanf("%i", &p_cap);

    printf("The station's depot's capacity: ");
    scanf("%i", &d_cap);

    *station = createStation(city_name, station_name, p_cap, d_cap);

    printf("\nThe city in which your station is located in: %s\n", station->city);
    printf("Your station's name: %s\n", station->name);
    printf("The station's platform's and depot's capacity: %i - %i\n", station->platform_capacity, station->depot_capacity);
    printf("The abbreviation your busses are going to take: %s\n\n", station->abbreviation);

    printf("If you're happy with the changes, press a key to jump to the bus managment tool..."); getch();

    busMenu(station);
}

void busMenu(STATION *station){
    clearScreen();

    printf("####Bus managment####\n\n");
    printf("\tNumber of buses on platform: %i\n", station->platform_size);
    printf("\tNumber of buses in depot: %i\n\n", station->depot_size);
    printf("You can do the following: \n\n");
    printf("|->1. Add a bus directly on the platform. If it doesn't fit in, we'll add it to the depot.\n");
    printf("|->2. Add a bus to the depot.\n");
    printf("|->3. Take out as many buses out from depot and onto the platform as possible.\n");
    printf("|->4. List the buses that are currently on the platform.\n");
    printf("|->5. List the buses that are currently in the depot.\n");
    printf("\n###########################\n");
    printf("\n|->0. EXIT - exit the application\n\n");

    int choice = takeAnswer();

    switch (choice) {
        case 1:
            printf("Name of the bus: ");
            char *name = getBuffer();

            int hour, minute;
            printf("Time of the bus' departure (HH:MM): ");
            scanf("%i%i", &hour, &minute);

            BUS bus = createBus(*station, name, createTime(hour, minute));
            insert(station, &station->root, bus);

            free(name);

            busMenu(station);
            break;
        case 2:
            printf("Name of the bus: ");
            name = getBuffer();

            printf("Time of the bus' departure (HH:MM): ");
            scanf("%i%i", &hour, &minute);

            bus = createBus(*station, name, createTime(hour, minute));
            enter(station, &station->first, &station->last, bus);

            free(name);

            printf("\nPress a key to continue...");
            getch();
            busMenu(station);
            break;
        case 3: takeBussesFromDepot(station, &station->root); busMenu(station); break;
        case 4:
            if (isEmptyBST(station->root)){
                printf("Platform is empty.\n\nPress a key to continue...");
                getch();
                busMenu(station);
            }

            listBST(station->root); printf("\nPress a key to continue..."); getch(); busMenu(station); break;
        case 5: listQ(station->first, station->last);  printf("\nPress a key to continue..."); getch(); busMenu(station); break;
        case 0: exit(1);
        default: printf("No such answer. Please try again."); getch(); busMenu(station);
    }
}