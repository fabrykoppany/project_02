#ifndef PROJECT_02_BUFFER_H
#define PROJECT_02_BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *getBuffer();
char *allocateMemory(int size);
void reallocateMemory(char **buffer);
bool onlyDigitsStr(char *buffer);

#endif //PROJECT_02_BUFFER_H
