#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
An anagram is a sequence of characters formed by rearranging the letters of another sequence such as "cinema", formed from "iceman";

Given two strings as parameters, create a function able to tell whether or not the first string is an anagram of the second.
*/

int is_anagram(char *param_1, char *param_2);
int my_strlen(char *String);

int main() {

    char string_One[] = "";
    char string_Two[] = "";
    int Result;

    Result = is_anagram(string_One, string_Two);

    printf("%i\n", Result);

    return 0;
}

int is_anagram(char *param_1, char *param_2) {
    int i, j;

    // 1. Calculate the string length of param_1
    int string_1_Length = my_strlen(param_1);

    // 2. Calculate the string length of param_2
    int string_2_Length = my_strlen(param_2);

    // 3. Check if string 1 and string 2 have the same length
    i = 0;
    if (string_1_Length == string_2_Length) {   
        while (i < string_1_Length) {
            j = 0;
            while (param_2[j] != '\0') {
                if (param_1[i] == param_2[j]) {
                    printf("Character param_1 is %c and match with %c in param_2\n", param_1[i], param_2[j]);
                    param_2[j] = 128;
                    printf("%i %c\n", i, param_2[j]);
                    break;
                } else {
                    printf("%c is not the same character of %c\n", param_1[i], param_2[j]);
                    j++;
                }
            }
            if (param_2[j] == '\0') {
                return 0;
            }
            i++;   
        }
    } else {
        return 0;
    }

    return 1;
}

int my_strlen(char *String) {
    int i = 0;
    int Counter = 0;
    while (String[i] != '\0') {
        Counter++;
        i++;
    }

    return Counter; 
}
