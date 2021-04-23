//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_BST_BUSES_H
#define PROJECT_02_BST_BUSES_H

#include "structures.h"
#include "queue_buses.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

BST_Node *createBST();
bool isEmptyBST(BST_Node *root);
void insert(STATION *station, BST_Node **root, BUS bus);
bool find(BST_Node *root, BUS key);
BST_Node *minimum(BST_Node *root);
BST_Node *maximum(BST_Node *root);
void findPredSucc(BST_Node *root, BST_Node **pre, BST_Node **suc, BUS key);
void delete(STATION *station, BST_Node **root, BUS key);
void takeBussesFromDepot(STATION *station, BST_Node **root);

#endif //PROJECT_02_BST_BUSES_H
