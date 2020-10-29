#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
- Create a function that displays the content of an array of strings. One word per line.
- Each word will be followed by a newline, including the last one.
*/

struct s_string_array {
    int size;
    char **array;
};

void my_print_words_array(struct s_string_array *String);

int main() {
    int counter = 0;
    int i = 0;
    int j = 0;
    
    struct s_string_array string_arrays;

    string_arrays.size = 3;
    string_arrays.array = (char **) malloc(string_arrays.size * sizeof(char));

    // first array of the 2D array
    string_arrays.array[0] = (char *) malloc(6 * sizeof(char));
    strcpy(string_arrays.array[0], "");

    // second array of the 2D array
    string_arrays.array[1] = (char *) malloc(6 * sizeof(char));
    strcpy(string_arrays.array[1], "hello");

    // third array of the 2D array
    string_arrays.array[2] = (char *) malloc(6 * sizeof(char));
    strcpy(string_arrays.array[2], "");

    struct s_string_array *p_string_arrays = &string_arrays;

    my_print_words_array(p_string_arrays);
    /*
    while (counter < string_arrays.size) {
        while ()
        print("The current character in the double pointer is %c\n", string_arrays.array[i][j]);
        i++;
    }
    */

    return 0;
}

void my_print_words_array(struct s_string_array *String) {
    // write some code here
    int i = 0;
    int j = 0;

    // outter loop counting each array  
    while (i < String->size) {
        // inner loop counting each character in each array
        while (String->array[i][j] != '\0') {
            printf("%c", String->array[i][j]);
            j++;
        }
        i++;
        // reset j back to 0;
        j = 0;
        printf("\n");
    }
};