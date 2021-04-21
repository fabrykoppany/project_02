//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_BST_BUSES_H
#define PROJECT_02_BST_BUSES_H

#include "buses.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Binary Search Tree - platform
 * data of the tree is of type BUS
 * sorting happens based on the departure time of a bus
 * early < late
 * platform has a capacity
 */
typedef struct BST_Node{
    BUS bus_data;
    struct AncestoreNode *left, *right;
}BST_Node;

#endif //PROJECT_02_BST_BUSES_H
