//
// Created by koppa on 2021. 04. 21..
//

#include "queue_buses.h"

queueNode *createQ(){
    queueNode *new = (queueNode *) calloc(1, sizeof(queueNode));

    if (new == NULL){
        printf("Error allocating memory!!!\n");
        exit(-1);
    }

    new->next = NULL;

    return new;
}

bool isEmptyQ(queueNode *first, queueNode *last){
    if (first == NULL || last == NULL){
        return true;
    }

    return false;
}

void addBus(queueNode **first, queueNode **last, BUS bus) {
    queueNode *new = createQ();

    new->bus_data = bus;

    if (isEmptyQ(*first, *last)) {
        *first = new;
        *last = new;
    } else {
        (*last)->next = new;
        *last = new;
    }
}

void enter(STATION *station, queueNode **first, queueNode **last, BUS bus){
    if (findQ(*first, *last, bus)) {
        printf("This bus already exists. Try another one.\n");
        return;
    }

    if (station->depot_size != station->depot_capacity) {
        addBus(first, last, bus);
        ++station->depot_size;
    } else {
        printf("No more space in depot.\n");
    }
}

BUS leave(STATION *station, queueNode **first, queueNode *last){
    if (!isEmptyQ(*first, last)) {
        queueNode *temp = *first;
        BUS temp_bus = temp->bus_data;

        *first = (*first)->next;
        free(temp);
        --station->depot_size;

        return temp_bus;
    }

    printf("The queue is empty.\n");
}

void listQ(queueNode *first, queueNode *last){
    if (!isEmptyQ(first, last)) {
        queueNode *aux = first;
        int counter = 0;

        while (aux != NULL) {
            ++counter;
            printf("%i.%s: leaves at %s\n", counter, aux->bus_data.name, aux->bus_data.departure_time.time_str);
            aux = aux->next;
        }

        return;
    }

    printf("Depot is empty.\n");
}

int getSizeQ(queueNode *first) {
    queueNode *aux = first;
    int size = 0;

    while (aux != NULL) {
        ++size;
        aux = aux->next;
    }

    return size;
}

bool findQ(queueNode *first, queueNode *last, BUS key){
    if (isEmptyQ(first, last)){
        return false;
    }

    queueNode *aux = first;

    while (aux != NULL){
        if ((!strcmp(aux->bus_data.name, key.name) && aux) || aux->bus_data.departure_time.full_time == key.departure_time.full_time){
            return true;
        }

        aux = aux->next;
    }

    return false;
}