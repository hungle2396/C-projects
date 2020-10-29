#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Create a function that splits a string of characters depending on a separator.
- The second argument is a unique charater separator
- The function should return an array which contains a string weapped between separator
- There cannot be any empty strings in your array
- The string given as an argument of the function won't be modifiable.
*/

typedef struct s_string_array {
    int size;
    char **array;
} string_array;

string_array *my_split(char *param_1, char *param_2);
int separator_Counter(char *String, char *separator);

int my_strlen(char *String);

int main() {
    char string_One[128] = "abc def gh-!";
    char separator[128] = "-";

    // Calculate the string length for string_One
    int string_one_Counter = my_strlen(string_One);

    // Calculate the string length for separator
    int separator_Counter = my_strlen(separator);

    string_array String;
    string_array *pointer_String = &String;

    pointer_String->size = 2;
    pointer_String->array = (char **) malloc(sizeof(char *) * pointer_String->size);

    pointer_String->array[0] = (char *) malloc(sizeof(char) * (string_one_Counter + 1));
    strcpy(pointer_String->array[0], string_One);

    pointer_String->array[1] = (char *)malloc(sizeof(char) * (separator_Counter + 1));
    strcpy(pointer_String->array[1], separator);

    string_array *Result = my_split(pointer_String->array[0], pointer_String->array[1]);

    printf("First String %s\n", Result->array[0]);
    printf("second String %s\n", Result->array[1]);
    printf("third String %s\n", Result->array[2]);

    free(Result);
    
    return 0;
}

string_array *my_split(char *param_1, char *param_2) {

    int i, j, k, param_1_Length; 

    // 0. Count the string length of the string 1
    param_1_Length = my_strlen(param_1);

    // 1. Create a pointer malloc for string_array structure
    string_array *pointer_final_Result = (string_array *) malloc(sizeof(string_array));

    // 2. Create an pointer size
    pointer_final_Result->size = separator_Counter(param_1, param_2);

    //printf("%i\n", pointer_final_Result->size);

    // 3. Create a malloc with how many pointers are needed in a double pointer
    pointer_final_Result->array = (char **) malloc(sizeof(char *) * pointer_final_Result->size);

    // 4. Create the amount of char size each pointer needed
    i = 0;
    while (i < pointer_final_Result->size) {
        pointer_final_Result->array[i] = (char *) malloc(sizeof(char) * param_1_Length);
        i++;
    }

    // 5. While loop that check for each character in string 1 and separate them with a separator
    i = 0, k = 0;
    while (i < pointer_final_Result->size) {
        j = 0;
        while (param_1[k] != '\0') {
            if (param_1[k] == param_2[0]) {
                //printf("Current character is the same as separator!\n", param_1[k]);
                //printf("%s\n", pointer_final_Result->array[0]);
                k++;
                break;
            } else {
                pointer_final_Result->array[i][j] = param_1[k];
                //printf("The current i is %i and char is %c\n", i, pointer_final_Result->array[i][j]);
                //printf("%s\n", pointer_final_Result->array[i]);
            }
            k++;
            j++;
        }
        pointer_final_Result->array[i][j] = '\0';
        i++;
    }

    return pointer_final_Result;

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

int separator_Counter(char *String, char *separator) {
    int i = 0, j = 0, Counter = 1;

    if (String[i] == '\0' && separator[i] == '\0') {
        return 0;
    }

    while (String[i] != '\0') {
        //printf("Current character is %c\n", String[i]);
        if (String[i] == separator[j]) {
            Counter++;
        }
        i++;
    }

    return Counter;
}
