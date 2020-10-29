#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *rcapitalize(char *param_1);
void my_strlen(char *String, int *Counting);
void my_downcase(char *String);

int main() {
    
    char normal_String[128] = "   But... This iS not THAT COMPLEX";

    char *Result = rcapitalize(normal_String);

    printf("%s\n", Result);

    free(Result);

    return 0;
}

char *rcapitalize(char *param_1) {
    int i = 0, j, Counter = 0;
    int *pointer_Counter = &Counter;
    char *final_Result = NULL;

    // Check if the string is empty
    if (param_1[i] == '\0') {
        return param_1;
    }

    // 1. Count the size of param_1
    my_strlen(param_1, pointer_Counter);

    // 2. Create a malloc based on the length of param_1
    final_Result = malloc(sizeof(char) * (Counter + 1));

    // 3. Down case the param_1 string
    my_downcase(param_1);

    //printf("%s\n", param_1);

    // 4. Find the space character, and then upper case the character before it
    i = 0;
    while (param_1[i] != '\0') {
        if (param_1[i] == ' ') {
            j = i - 1;
            //printf("The current character is %c\n", param_1[i]);
            if (param_1[j] >= 'a' && param_1[j] <= 'z') {
                final_Result[j] = param_1[j] - 32;
                //printf("previous character %c changed to %c\n", param_1[j], final_Result[j]);
            }
        };

        final_Result[i] = param_1[i];
        //printf("Current char added in final string is %c\n", final_Result[i]);
        i++;
    }

    if (param_1[i] == '\0') {
        j = i - 1;
        if (param_1[j] >= 'a' && param_1[j] <= 'z') {
            final_Result[j] = param_1[j] - 32;
            //printf("previous character %c changed to %c\n", param_1[j], final_Result[j]);
        }
        final_Result[i] = '\0';
    }
    
    return final_Result;
    
}

void my_strlen(char *String, int *Counting) {
    int i = 0;

    while (String[i] != '\0') {
        (*Counting)++;
        i++;
    }
}

void my_downcase(char *String) {
    int i = 0;

    while (String[i] != '\0') {
        if (String[i] >= 'A' && String[i] <= 'Z') {
            String[i] = String[i] + 32;
        }
        i++;
    }

}