#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a function my_union that takes two strings and returns
- without doubles, the characters that appear in either one of the strings.
*/

char *inter(char *param_1, char *param_2);
void my_strlen(char *String, int *Counting);

int main() {
    
    char string_One[128] = "nothing";
    char string_Two[128] = "This sentence hides nothing";  // nothing -> nothigg     

    char *Result = inter(string_One, string_Two);

    printf("%s\n", Result);
    
    return 0;
}

char *inter(char *param_1, char *param_2) {
    int i, j, k = 0, Counter = 0;
    int *pointer_Counter = &Counter;
    char *duplicate_String = NULL;
    char *final_String = NULL;
    

    // 1. Remove duplicate chars in string 1
    i = 0, j = 0;
    // 1. 1 Going through each character in the string 1
    while (param_1[i] != '\0') {
        j = i + 1;
        // 1.2 find the duplicate characters
        while (param_1[j] != '\0') {
            if (param_1[j] == param_1[i]) {
                printf("The current duplicate char is %c\n", param_1[j]);
                param_1[j] = param_1[j+1];                               
                k = j + 1;
                while (param_1[k] == param_1[i]) {
                    printf("The next char is the same again is %c\n", param_1[k]);
                    param_1[j] = param_1[k+1];
                    k++;
                }
                j++;
            } else {
                j++;
            }
        }
        i++;
    }
    
    
    // 2. Creating a malloc based on string length of string 1
    final_String = (char *) malloc(Counter * sizeof(char) + 1);

    // 3. While loop that compare both string 1 and string 2 chars
    i = 0, k = 0;
    while (param_1[i] != '\0') {
        //printf("Testing 1\n");
        j = 0;
        // 3.1 Comparing current char in string 1 to each character in string 2
        while (param_2[j] != '\0') {
            //printf("Testing 2\n");
            if (param_2[j] == param_1[i]) {
                //printf("The current char in both string is %c\n", param_1[i]);
                final_String[k] = param_1[i];
                k++;
                break;
            } else {
                j++;
            }
        }
        i++;
    }

    final_String[i] = '\0';
    //printf("The final string is %s\n", final_String);
    return final_String;
}

void my_strlen(char *String, int *Counting) {
    int i = 0;

    while (String[i] != '\0') {
        (*Counting)++;
        i++;
    }
}