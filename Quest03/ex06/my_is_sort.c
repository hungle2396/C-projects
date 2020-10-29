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

struct s_integer_array {
    int size;
    int *array;
};

bool my_is_sort(struct s_integer_array *a);

int main() {
    int Size = 3;
    int Array[] = {0, 1, 2};
    
    struct s_integer_array integer_array = {
        .size = Size,
        .array = Array
    };

    //integer_array.size = Size;
    //integer_array.array = Array;

    struct s_integer_array *pointer_integer_array = &integer_array;

    //allocating the memory address for the integer_array
    //pointer_integer_array->array = (int *) malloc(pointer_integer_array->size * sizeof(int));


    bool result = my_is_sort(pointer_integer_array);

    printf("%i\n", result);
    
    return 0;
}


bool my_is_sort(struct s_integer_array *a) {

    
    int i = 0;                          // 1. I created an index here
    int temp_Number_1;                  // 2. I created a temp number 1 as a previous number 
    int temp_Number_2;                  // 3. temp number 2 is the current number that will be compared to temp number 1 
    int asc_des_Order = 0;              // 4. This will determine if the order is ascending or descending
                                        // 4.1 I will use asc_des_Order = 0 as neutral, 1 for ascending, and -1 for descending
    // This is probably not needed      You need it to be neutral because you don't know if the array is ascending or descending yet
    if (a->size == 0) {
        return true;                    
    }                                
    
    // calculate the length of integer array
    while (i < a->size) {
        printf("The current number is %i\n", a->array[i]);
        // if i == 0, store the very first number to first_Number for later comparison
        if (i == 0) {
            temp_Number_1 = a->array[i];       
            printf("This is the first number %i\n", temp_Number_1);
            i++;
        // check for second number
        } else if (i == 1) {
            temp_Number_2 = a->array[i];      
            printf("This is the second number %i\n", temp_Number_2);
            // current number and previous number is the same
            if (temp_Number_2 == temp_Number_1) {           // this is where you do the comparison between those 2 temp numbers
                printf("temp_Number_2 is equal to temp_Number_1\n");
                asc_des_Order = 0;               
                temp_Number_1 = temp_Number_2;        
                i++;                          
            // current number is greater than previous number (Ascend)
            } else if (temp_Number_2 > temp_Number_1) {           
                printf("temp_Number_2 is greater than temp_Number_1\n");
                asc_des_Order = 1;
                temp_Number_1 = temp_Number_2;
                i++;
            // current Number is lesser than previous number (Descend)
            } else if (temp_Number_2 < temp_Number_1) {
                printf("temp_Number_2 is lesser than temp_Number_1\n");
                asc_des_Order = -1;
                temp_Number_1 = temp_Number_2;
                i++;
            }
        } else if (i > 1 && asc_des_Order == 0) {
            // current number
            temp_Number_2 = a->array[i];
            printf("This is index number %i which is %i\n", i, temp_Number_2);
            // Checking if the current number is greater, lesser or equal to the previous number
            if (temp_Number_2 == temp_Number_1) {
                asc_des_Order = 0;
                temp_Number_1 = temp_Number_2;
                i++;
            } else if (temp_Number_2 > temp_Number_1) {
                asc_des_Order = 1;
                temp_Number_1 = temp_Number_2;
                i++;
            } else {
                asc_des_Order = -1;
                temp_Number_1 = temp_Number_2;
                i++;
            }
        // if the current number is ascend
        } else if (i > 1 && asc_des_Order == 1) {
            temp_Number_2 = a->array[i];

            // current number is still ascending (equal or greater than prev number)
            if (temp_Number_2 >= temp_Number_1) {
                temp_Number_1 = temp_Number_2;
                i++;
            // current number is lesser than previous number (false)
            } else {
                return false;
            }
        // if the current number is descend
        } else if (i > 1 && asc_des_Order == -1) {
            temp_Number_2 = a->array[i];

            // current number is still descending (equal to lesser than prev number)
            if (temp_Number_2 <= temp_Number_1) {
                temp_Number_1 = temp_Number_2;
                i++;
            // current number is greater than the previous number (false)
            } else {
                return false;
            }
        } 
    }
    return true;
}
