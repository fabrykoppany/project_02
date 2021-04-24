//
// Created by koppa on 2021. 04. 21..
//

#include "bst_buses.h"

BST_Node *createBST(){
    BST_Node *new_node = (BST_Node *) calloc(1, sizeof(BST_Node));

    if (new_node == NULL){
        printf("Error allocating memory!!!");
        exit(-1);
    }

    return new_node;
}

bool isEmptyBST(BST_Node *root){
    if (root == NULL){
        return true;
    }

    return false;
}

void insert(STATION *station, BST_Node **root, BUS bus) {
    if (findBST(*root, bus)){
        printf("This bus already exists. Try another one.");
        return;
    }

    if (station->platform_capacity == station->platform_size){
        printf("The platform is full. Now adding to depot...\n");
        enter(station, &station->first, &station->last, bus);
        return;
    } else {
        if (isEmptyBST(*root)) {
            *root = createBST();
            (*root)->left = NULL;
            (*root)->right = NULL;
            (*root)->bus_data = bus;
            ++station->platform_size;
        } else {
            if (bus.departure_time.full_time <= (*root)->bus_data.departure_time.full_time) {
                insert(station, &(*root)->left, bus);
            } else {
                insert(station, &(*root)->right, bus);
            }
        }
    }
}

bool findBST(BST_Node *root, BUS key){
    if (isEmptyBST(root)){
        return false;
    } else {
        if (key.departure_time.full_time < root->bus_data.departure_time.full_time){
            findBST(root->left, key);
        } else{
            if (key.departure_time.full_time > root->bus_data.departure_time.full_time){
                findBST(root->right, key);
            } else{
                return true;
            }
        }
    }
}

BST_Node *minimum(BST_Node *root){
    BST_Node *ptr = root;

    while (ptr && ptr->left != NULL){
        ptr = ptr->left;
    }

    return ptr;
}

BST_Node *maximum(BST_Node *root){
    BST_Node *ptr = root;

    while (ptr && ptr->right != NULL){
        ptr = ptr->right;
    }

    return ptr;
}

void findPredSucc(BST_Node *root, BST_Node **pre, BST_Node **suc, BUS key){
    if (isEmptyBST(root)){
        return;
    } else{
        if (root->bus_data.departure_time.full_time == key.departure_time.full_time){
            if (root->left != NULL){
                *pre = maximum(root->left);
            }

            if (root->right != NULL){
                *suc = minimum(root->right);
            }
        }

        if (root->bus_data.departure_time.full_time > key.departure_time.full_time){
            *suc = root;
            findPredSucc(root->left, pre, suc, key);
        } else{
            *pre = root;
            findPredSucc(root->right, pre, suc, key);
        }
    }
}

void delete(STATION *station, BST_Node **root, BUS key) {
    if (isEmptyBST(*root)){
        return;
    }

    if ((*root)->left != NULL) {
        if (key.departure_time.full_time < (*root)->bus_data.departure_time.full_time) {
            delete(station, &(*root)->left, key);
        }
    }

    else {
        if ((*root)->right != NULL) {
            if (key.departure_time.full_time > (*root)->right->bus_data.departure_time.full_time) {
                delete(station, &(*root)->right, key);
            }
        }

        else {
            if ((*root)->bus_data.departure_time.full_time == key.departure_time.full_time) {
                if ((*root)->left == NULL) {
                    BST_Node *temp = (*root)->right;
                    free(*root);
                    *root = temp;
                    --station->platform_size;
                    return;
                } else {
                    if ((*root)->right == NULL) {
                        BST_Node *temp = (*root)->left;
                        free(*root);
                        *root = temp;
                        --station->platform_size;
                        return;
                    }
                }

                BST_Node *temp = minimum((*root)->right);
                (*root)->bus_data = temp->bus_data;
                delete(station, &(*root)->right, temp->bus_data);
            }
            else{
                printf("No such element.\n");
                return;
            }
        }
    }

    return;
}

void takeBussesFromDepot(STATION *station, BST_Node **root){
    while (station->platform_capacity > station->platform_size && !isEmptyQ(station->first, station->last)){
        BUS bus = leave(station, &station->first, station->last);
        insert(station, root, bus);
    }
}

void listBST(BST_Node *root){
    if (root == NULL){
        return;
    }

    int counter = 0;

    listBST(root->left);
    ++counter;
    printf("%i.%s: leaves at %s\n", counter, root->bus_data.name, root->bus_data.departure_time.time_str);
    listBST(root->right);
}