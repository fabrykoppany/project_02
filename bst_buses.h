//
// Created by koppa on 2021. 04. 21..
//

#ifndef PROJECT_02_BST_BUSES_H
#define PROJECT_02_BST_BUSES_H

#include "structures.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

BST_Node *create();
bool isEmpty(BST_Node *root);
void insert(BST_Node **root, BUS bus);
bool find(BST_Node *root, int key);
BST_Node *minimum(BST_Node *root);
BST_Node *maximum(BST_Node *root);
void findPredSucc(BST_Node *root, BST_Node **pre, BST_Node **suc, int key);
void delete(BST_Node **root, int key);

#endif //PROJECT_02_BST_BUSES_H
