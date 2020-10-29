#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
Your function should return true if the integer array is sorted in either ASC(ascending) or DESC(descending) order. Your function should return false if the integer array is not sorted.

Input: [1, 1, 2]
Output: true

Input: [2, 1, -1]
Output: true

Input: [4, 7, 0, 3]
Output: false
*/

typedef struct s_integer_array {
    int size;
    int *array;
} s_integer_array;

bool my_is_sort(s_integer_array *param_1);

int main() {
    int Size = 5;
    int Array[] = {3, 2, 1};
    
    s_integer_array integer_array = {
        .size = Size,
        .array = Array
    };

    //integer_array.size = Size;
    //integer_array.array = Array;

    s_integer_array *pointer_integer_array = &integer_array;
    pointer_integer_array->size = Size;

    //allocating the memory address for the integer_array
    //pointer_integer_array->array = (int *) malloc(pointer_integer_array->size * sizeof(int));


    bool result = my_is_sort(pointer_integer_array);

    //printf("%i\n", result);
    
    return 0;
}

bool my_is_sort(s_integer_array *param_1) {
    int runner = 1;
    int asc = 0;

    
    while (param_1->array[runner]) {
        printf("while loop in function for bool\n");
        if (param_1->array[runner] == param_1->array[runner - 1]) {
            printf("Testing 0!\n");
            printf("Current number is %i\n", param_1->array[runner - 1]);
            runner++;
        // ascending
        } else if (param_1->array[runner] < param_1->array[runner - 1]) {
            printf("Testing 1!\n");
            printf("Current number is %i\n", param_1->array[runner - 1]);
            asc = 1;
            break;
        // descending
        } else if (param_1->array[runner] > param_1->array[runner - 1]) {
            printf("Testing 2!\n");
            printf("Current number is %i\n", param_1->array[runner + 1]);
            asc = -1;
            break;
        }
    }
    
    if (asc == 1) {
        printf("ascending!\n");
    } else if (asc == -1) {
        printf("descending\n");
    // all the numbers in the array are equal to each other
    } else if (asc == 0) {
        printf("all numbers are the same!\n");
        return true;
    }

    // while loop to check if the array is correct
    // reset runner back to 0
    /*
    runner = 0;
    while (runner < param_1->size) {

    }*/

}