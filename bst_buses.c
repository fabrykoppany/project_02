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
        printf("No two buses can leave at the same time.");
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

bool busNameTakenBST(BST_Node *root, const char *bus_name){
    if (root == NULL){
        return false;
    }

    if (strcmp(root->bus_data.name, bus_name) == 0){
        return true;
    }
    else {
        if (busNameTakenBST(root->left, bus_name) == false) {
            return busNameTakenBST(root->right, bus_name);
        } else {
            return true;
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

BST_Node *delete(STATION *station, BST_Node *root, BUS key) {
    if (isEmptyBST(root)){
        return root;
    }

    if (key.departure_time.full_time < root->bus_data.departure_time.full_time){
        root->left = delete(station, root->left, key);
    }

    else{
        if (key.departure_time.full_time > root->bus_data.departure_time.full_time){
            root->right = delete(station, root->right, key);
        }

        else{
            if (root->left == NULL){
                BST_Node *temp = root->right;
                free(root);
                --station->platform_size;
                return temp;
            }

            else{
                if (root->right == NULL){
                    BST_Node *temp = root->left;
                    free(root);
                    --station->platform_size;
                    return temp;
                }
            }

            BST_Node *temp = minimum(root->right);
            root->bus_data = temp->bus_data;
            root->right = delete(station, root->right, temp->bus_data);
        }
    }

    return root;
}

BST_Node *emptyPlatform(STATION *station, BST_Node *root){
    while (!isEmptyBST(root)){
        root = delete(station, root, minimum(root)->bus_data);
    }

    return root;
}

void takeBussesFromDepot(STATION *station, BST_Node **root){
    while (station->platform_capacity > station->platform_size && !isEmptyQ(station->first, station->last)){
        BUS bus = leave(station, &station->first, station->last);
        insert(station, root, bus);
    }
}

void listBST(BST_Node *root) {
    if (root == NULL){
        return;
    }

    listBST(root->left);
    printf("%s: leaves at %s\n", root->bus_data.name, root->bus_data.departure_time.time_str);
    listBST(root->right);
}