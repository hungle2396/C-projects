#include <stdio.h>
#include <stdlib.h> 

/* 
Create a function my_range which returns a malloc's array of integers. This integer array should contain all values between min and max.

Min include - max excluded.

if min value is greater or equal to max's value, a null pointer should be returned.

*/

int *my_range(int min, int max);

int main() {

    int min = 1;
    int max = 10;

    my_range(min, max);

    //printf("The numbers between the min and max are: %i\n", my_range(min, max));
    
    return 0;
}

int *my_range(int min, int max) {
    int i = 0;
    int cpy_min = min;
    int cpy_max = max;

    printf("Testing\n");
    int array_Size = cpy_max - cpy_min;
    printf("The current array_Size is %i\n", array_Size);

    int *result_Array = (int *)malloc(array_Size * sizeof(int));                         

    if (result_Array != NULL) {
        while (cpy_min < cpy_max) {
            cpy_min++;
            printf("The current cpy_min is now %i\n", cpy_min);
            result_Array[i] = cpy_min;
            printf("The current integer in the array is: %i\n", result_Array[i]);
            i++; 
            printf("current i is now: %i\n", i);
        }     
    }
    
    /*
    while (i > 0) {
        printf("The array of numbers between min and max are: %i\n", result_Array[i]);
        i--;
    }
    */

    printf("The first number of the array is: %i\n", *result_Array);

    return result_Array;
    
    
}