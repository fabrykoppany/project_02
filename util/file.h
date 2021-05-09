#ifndef PROJECT_02_FILE_H
#define PROJECT_02_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void writeStringToFile(FILE *file, char *str);
char *readStringFromFile(FILE *file);
bool readStringToField(FILE *file, char **field);

#endif //PROJECT_02_FILE_H