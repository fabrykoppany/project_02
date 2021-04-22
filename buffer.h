//
// Created by koppa on 2021. 04. 22..
//

#ifndef PROJECT_02_BUFFER_H
#define PROJECT_02_BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getBuffer();
char *allocateMemory(int size);
void reallocateMemory(char **buffer);

#endif //PROJECT_02_BUFFER_H
