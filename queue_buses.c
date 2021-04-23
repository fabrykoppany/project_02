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

void enter(STATION *station, queueNode **first, queueNode **last, BUS bus){
    if (station->depot_size != station->depot_capacity) {
        queueNode *new = createQ();

        new->bus_data = bus;

        if (isEmptyQ(*first, *last)) {
            *first = new;
            *last = new;
        } else {
            (*last)->next = new;
            *last = new;
        }

        ++station->depot_size;
    }

    else{
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