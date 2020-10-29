#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Count the size of each elements in an array.
Create a function my_count_on_it, which receives a string array as parameter and returns an array with the length of each strings.
*/

typedef struct s_string_array {
    int size;
    char **array;
} string_array;

typedef struct s_integer_array {
    int size;
    int *array;
} integer_array;

integer_array *my_count_on_it(string_array *String);

int main (void) {
    
    /*
    // struct string_array malloc
    struct s_string_array string_array = {
        .size = 3,
        .array = (char **) malloc(string_array.size * sizeof(char))
    };

    string_array.array[0] = (char *) malloc(10 * sizeof(char));
    strcpy(string_array.array[0], "abc");

    string_array.array[1] = (char *) malloc(10 * sizeof(char));
    strcpy(string_array.array[1], "defgh sd");    

    string_array.array[2] = (char *) malloc(10 * sizeof(char));
    strcpy(string_array.array[2], "12");

    struct s_string_array *pointer_string_array = &string_array;
    */
    string_array String;
    string_array *pointer_String = &String;

    pointer_String->size = 3;
    // give you 3 char allocation memory for double pointer 0, 1, and 2
    pointer_String->array = (char **) malloc(pointer_String->size * sizeof(char));

    // malloc the string 0 
    pointer_String->array[0] = (char *) malloc(5 * sizeof(char)); 
    strcpy(pointer_String->array[0], "abc");

    // malloc the string 1
    pointer_String->array[1] = (char *) malloc(10 * sizeof(char)); 
    strcpy(pointer_String->array[1], "defghi");

    // malloc the string 2
    pointer_String->array[2] = (char *) malloc(5 * sizeof(char)); 
    strcpy(pointer_String->array[2], "abc");

    my_count_on_it(pointer_String);

    return 0;
}

integer_array *my_count_on_it(string_array *String) {


    int i = 0;
    int j = 0;
    int counter = 0;

    integer_array Integer;
    integer_array *pointer_Integer = malloc(sizeof(integer_array));

    pointer_Integer->size = String->size;
    pointer_Integer->array = (int *) malloc(pointer_Integer->size * sizeof(int));

    // outer loop that goes through each array of string
    while (i < String->size) {
        // inner loop that goes through each char in each string
        while (String->array[i][j] != '\0') {
            counter++;
            j++;
        }
        pointer_Integer->array[i] = counter;
        printf("In array index number %i has %i characters\n", i, pointer_Integer->array[i]);
        i++;

        // reset j and counter back to  0;
        j = 0;
        counter = 0; 
    }

    return pointer_Integer;

}