#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_strlen(char *str) {

    int stringLength = 0;

    // looping on each characters inside the string and count
    while (*str != '\0') {
        stringLength++; // increment the number count
        str++; // if the character is not '\0', go to next character
    }

    return stringLength;
}

int main() {

    char stringCharacters[] = "Hello World!";
    /* char *String = NULL;
    String = &stringCharacters; */

    int charLength = my_strlen(stringCharacters);

    printf("The length of the characters in the string: %i", charLength);


    return 0;
}