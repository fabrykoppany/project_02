#include "file.h"

/**
 * Writes a string to a file. This string can later be read
 * using the readStringFromFile method.
 *
 * @param file - An open file handle to write to.
 * @param str - The string you would like to write to the file.
 */
void writeStringToFile(FILE *file, char *str) {
    // Strings are written to files in an interesting way:
    // First, we store the actual length of the string.
    // Afterwards, we store the string itself in the file.
    size_t length = strlen(str);

    fwrite(&length, sizeof(size_t), 1, file);
    fwrite(str, sizeof(char), length, file);
}

/**
 * Reads a string from a file. This string must have been
 * written to the file using the writeStringToFile method.
 *
 * @param file - An open file handle to read from.
 * @return The string found at the current position of the file.
 */
char *readStringFromFile(FILE *file) {
    // First, read the actual length of the string.
    size_t length;
    fread(&length, sizeof(size_t), 1, file);

    // Allocate enough characters, plus one for the null terminator.
    char *str = (char *) malloc((length + 1) * sizeof(char));

    if (str == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    // Read the actual string.
    fread(str, sizeof(char), length, file);

    // Add the required null-terminator.
    str[length] = '\0';
    return str;
}

/**
 * Reads a string from a file, and then populates a given
 * field inside a structure. This string must have been
 * written to the file using the writeStringToFile method.
 *
 * @param file - An open file handle to read from.
 * @param field - A pointer pointing to the variable to be filled.
 * @return A boolean representing the success state of the method.
 */
bool readStringToField(FILE *file, char **field) {
    // First, read the string from the file...
    char *str = readStringFromFile(file);

    if (str == NULL) {
        // Memory could not be allocated.
        return false;
    }

    // Set the field now!
    (*field) = str;
    return true;
}