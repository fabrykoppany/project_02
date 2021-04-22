//
// Created by koppa on 2021. 04. 22..
//

#include "buffer.h"

char *getBuffer(){
    char *buffer = (char *) malloc(20 * sizeof(char));

    if (buffer == NULL){
        printf("Error allocating memory!!!");
        exit(-1);
    }

    printf("Text to be added: ");
    scanf("%[^\n]", buffer);

    return buffer;
}