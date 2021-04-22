//
// Created by koppa on 2021. 04. 21..
//

#include "bst_buses.h"

BST_Node *create(){
    BST_Node *new_node = (BST_Node *) calloc(1, sizeof(BST_Node));

    if (new_node == NULL){
        printf("Error allocating memory!!!");
        exit(-1);
    }

    return new_node;
}

bool isEmpty(BST_Node *root){
    if (root == NULL){
        return true;
    }

    return false;
}

void insert(BST_Node **root, BUS bus){
    if (isEmpty(*root)){
        *root = create();
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->bus_data = bus;
    } else{
        if (bus.departure_time.full_time <= (*root)->bus_data.departure_time.full_time){
            insert(&(*root)->left, bus);
        } else{
            insert(&(*root)->right, bus);
        }
    }
}

bool find(BST_Node *root, int key){
    if (isEmpty(root)){
        return false;
    } else {
        if (key < root->bus_data.departure_time.full_time){
            find(root->left, key);
        } else{
            if (key > root->bus_data.departure_time.full_time){
                find(root->right, key);
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

void findPredSucc(BST_Node *root, BST_Node **pre, BST_Node **suc, int key){
    if (isEmpty(root)){
        return;
    } else{
        if (root->bus_data.departure_time.full_time == key){
            if (root->left != NULL){
                *pre = maximum(root->left);
            }

            if (root->right != NULL){
                *suc = minimum(root->right);
            }
        }

        if (root->bus_data.departure_time.full_time > key){
            *suc = root;
            findPredSucc(root->left, pre, suc, key);
        } else{
            *pre = root;
            findPredSucc(root->right, pre, suc, key);
        }
    }
}

void delete(BST_Node **root, int key){
    if (isEmpty(*root)){
        return;
    }

    if (key < (*root)->bus_data.departure_time.full_time){
        delete(&(*root)->left, key);
    }

    else {
        if (key > (*root)->right->bus_data.departure_time.full_time){
            delete(&(*root)->right, key);
        }

        else{
            if ((*root)->left == NULL){
                BST_Node *temp = (*root)->right;
                free(*root);
                *root = temp;
                return;
            }

            else{
                if ((*root)->right == NULL){
                    BST_Node *temp = (*root)->left;
                    free(*root);
                    *root = temp;
                    return;
                }
            }

            BST_Node *temp = minimum((*root)->right);
            (*root)->bus_data = temp->bus_data;
            delete(&(*root)->right, temp->bus_data.departure_time.full_time);
        }
    }

    return;
}