#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_string_array {
    int size;
    char **array;
} string_array;

char *my_join(string_array *param_1, char *param_2);

int main() {
    int i;
    int j;
    string_array String;
    string_array *pointer_String = &String;
    char *join_Char = "";

    pointer_String->size = 4;
    // dynamic memory allocation for 2D array
    pointer_String->array = (char **) malloc(pointer_String->size * sizeof(char *));

    pointer_String->array[0] = (char *) malloc(10 * sizeof(char));
    strcpy(pointer_String->array[0], "");

    pointer_String->array[1] = (char *) malloc(10 * sizeof(char));
    strcpy(pointer_String->array[1], "");

    pointer_String->array[2] = (char *) malloc(10 * sizeof(char));
    strcpy(pointer_String->array[2], "");

    pointer_String->array[3] = (char *) malloc(10 * sizeof(char));
    strcpy(pointer_String->array[3], "");

    char *Result = my_join(pointer_String, join_Char);

    printf("The joined string is %s\n", Result);

    return 0;
}

char *my_join(string_array *param_1, char *param_2) {
    int i = 0;
    int j = 0;
    int x = 0;
    int string_A_Counter = 0;
    int string_B_Counter = 0;
    int string_B_malloc_Counter;
    char *final_Result = NULL;

    if (param_1->array[0][0] == '\0' && param_2[j] == '\0') {
        //printf("Return NULL\n");
        return NULL;
    }

    // counting each character in each array in the 2D array (String A)
    for (i = 0; i < param_1->size; i++) {
        for (j = 0; param_1->array[i][j] != '\0'; j++) {
            //printf("The current character in array %i is %c\n", i, param_1->array[i][j]);
            string_A_Counter++;
        }
    };

    // counting each character in string B
    for (i = 0; param_2[i] != '\0'; i++) {
        //printf("The current character in string B is %c\n", param_2[i]);
        string_B_Counter++;
    };

    string_B_malloc_Counter = (param_1->size - 1) * string_B_Counter; 

    final_Result = (char *) malloc((string_A_Counter + string_B_Counter + 1) * sizeof(char));

    // going through each characters in string A and B

    // reset i and j back to 0
    i = 0;
    j = 0;
    // while i is less than the row in 2D array
    while (i < param_1->size) {
        while (param_1->array[i][j] != '\0') {
            printf("The current character in string A being stored in the malloc is %c\n", param_1->array[i][j]);
            final_Result[x] = param_1->array[i][j];
            printf("The current result of final string is %s\n", final_Result);
            j++;
            x++;
        }

        // reset j back to 0
        j = 0;
        while (param_2[j] != '\0' && i < param_1->size - 1) {
            final_Result[x] = param_2[j];
            j++;
            x++;
        }

        // reset j back to 0;
        j = 0;

        // increment i for next iteration
        i++;
    };

    final_Result[x] = '\0';
    return final_Result;
}

