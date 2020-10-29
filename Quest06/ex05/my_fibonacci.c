#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Create a function my_fibonacci that returns the n-th element of the Fibonacci sequence, the first element being at the 0 index. We'll consider that the Fibonacci sequence starts like this : 0, 1, 1, 2.

If the value is less than 0, the function should return -1.

It should be prototyped:

recursive will be helpful here.
*/

int my_fibonacci(int param_1);

int main() {

    int number = 6;
    int result;

    result = my_fibonacci(number);

    return 0;
}

int my_fibonacci(int param_1) {

    int final_Result;
    int first_Number;
    int second_Number;
    int i = 0;

    // if the value is less than 0
    if (param_1 < 0) {
        return -1;
    }
    
    while (i <= param_1) {
        if (i == 0) {
            first_Number = 0;
            final_Result = first_Number;
        } else if (i == 1) {
            second_Number = 1;
            final_Result = second_Number;
        } else if (i == 2) {
            final_Result = first_Number + second_Number;
        } else {
            first_Number = second_Number; // 1 1 2
            second_Number = final_Result; // 1 2 3 
            final_Result = first_Number + second_Number; // 2 3 5
        }
        i++;
    }

    return final_Result;
}