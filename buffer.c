//
// Created by koppa on 2021. 04. 22..
//

#include "buffer.h"

char *getBuffer(){
    char *buffer = allocateMemory(20);

    printf("Text to be added: ");
    scanf("%[^\n]", buffer);

    reallocateMemory(&buffer);

    return buffer;
}

char *allocateMemory(int size){
    char *buffer = (char *) malloc(size * sizeof(char));

    if (buffer == NULL){
        printf("Error allocating memory!!!");
        exit(-1);
    }

    return buffer;
}

void reallocateMemory(char **buffer){
    *buffer = realloc(*buffer, strlen(*buffer) + 1);
}