#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
- Write a function that takes a string, and returns another string which contains exactly 
- one space between words, with no spaces or tabs either at the beginning or the end.

- A "word" is defined as a part of a string delimited either by spaces/tabs, or 
- by the start/end of the string
*/

char *my_strip(char *param_1);
int my_strlen(char *String);

int main() {

    char string_One[128] = "No  S***    Sherlock...";

    char *Result = my_strip(string_One);

    printf("%s\n", Result);

    free(Result);
    
    return 0;
}

char *my_strip(char *param_1) {
    bool Space = false;
    int i = 0, j = 0;

    // 1. Count string length for the malloc later
    int param_1_Length = my_strlen(param_1);

    // 2. Create a malloc for Result string
    char *result_String = (char *) malloc(sizeof(char) * param_1_Length);

    // 3. while loop to take away the duplicate spaces
    while (param_1[i] != '\0') {
        if (param_1[i] == ' ' && Space == false) {
            //printf("Current character is a space and false!\n");
            Space = false;
        } else if (param_1[i] == ' ' && Space == true) {
            //printf("Current character is a space and added to the final string\n");
            result_String[j] = param_1[i];
            j++;
            Space = false; 
        } else if (param_1[i] != ' ') {
            //printf("Current character is %c and added to the final string\n", param_1[i]);
            result_String[j] = param_1[i];
            j++;
            Space = true;
        }
        i++;
    }

    // 4. Replace the space at the end with null ('\0') if there is any
    if (result_String[j - 1] == ' ') {
        result_String[j - 1] = '\0';
    } else {
        result_String[j] = '\0';
    }
    
    return result_String;
}

int my_strlen(char *String) {
    int i = 0;
    int Counter = 0;

    while (String[i] != '\0') {
        //printf("Current char is %c\n", String[i]);
        Counter++;
        i++;
    }

    return Counter; 
}