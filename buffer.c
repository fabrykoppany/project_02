//
// Created by koppa on 2021. 04. 22..
//

#include "buffer.h"

char *getBuffer(){
    char *buffer = allocateMemory(20);

    scanf(" %[^\n]", buffer);

    reallocateMemory(&buffer);

    return buffer;
}

char *allocateMemory(int size){
    char *buffer = (char *) calloc(1, size * sizeof(char));

    if (buffer == NULL){
        printf("Error allocating memory!!!");
        exit(-1);
    }

    return buffer;
}

void reallocateMemory(char **buffer){
    *buffer = realloc(*buffer, strlen(*buffer) + 1);
}

bool onlyDigitsStr(char *buffer){
    for (int i = 0; i < strlen(buffer); ++i){
        if (!isdigit(buffer[i])){
            return false;
        }
    }

    return true;
}