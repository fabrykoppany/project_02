#ifndef PROJECT_02_BST_BUSES_H
#define PROJECT_02_BST_BUSES_H

#include "../model/structures.h"
#include "queue_buses.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

BST_Node *createBST();
bool isEmptyBST(BST_Node *root);
void addBSTBus(BST_Node **root, BUS bus);
void insert(STATION *station, BST_Node **root, BUS bus);
bool findBST(BST_Node *root, BUS key);
bool busNameTakenBST(BST_Node *root, const char *bus_name);
BST_Node *minimum(BST_Node *root);
BST_Node *maximum(BST_Node *root);
void findPredSucc(BST_Node *root, BST_Node **pre, BST_Node **suc, BUS key);
BST_Node *delete(STATION *station, BST_Node *root, BUS key);
BST_Node *emptyPlatform(STATION *station, BST_Node *root);
void takeBusesFromDepot(STATION *station, BST_Node **root);
void listBST(BST_Node *root);
int sizeBST(BST_Node *root);

#endif //PROJECT_02_BST_BUSES_H
