#include <stdio.h>
#include <stdlib.h>

/* 
The atoi() function in C takes string (which represents an integer) as an argument and returns its value of type int. So basically the function is used to convert a string argument to an integer.
Syntax:

int atoi(const char strn);

Parameters: The function accepts one parameter strn which refers to the string argument that is needed to be converted into its integer equivalent.

Return Value: If strn is a valid input, then the function returns the equivalent integer number for the passed string number. If no valid conversion takes place, then the function returns zero.
*/
int power_Function(int num, int power);
int my_atoi(char *param_1);

int main() {

    char random_String[] = "-45";

    int result = my_atoi(random_String);

    printf("The conversion string %s is now %i\n", random_String, result);

    return 0;
}

int my_atoi(char *param_1) {

    int i = 0;
    int counter = 0;
    int final_Result = 0;
    int temp_Number;
    char negative_sign = 0;

    // find the how many numbers in the string and if the string has a negative sign or not
    while (param_1[i] != '\0') {
        // check for the negative sign first
        if (param_1[i] == 45) {
            negative_sign = 1;
        // if it's a number, then increment counter
        } else {
            counter++;
        }
        i++;
    }

    // reset i back to 0
    i = 0;
    while (param_1[i] != '\0') {
        if (param_1[i] == 45) {
            i++;
        } else {
            if (counter > 0) {
                temp_Number = param_1[i] - 48;
                final_Result = final_Result + power_Function(temp_Number, counter);
            }
            i++;
            counter--;
        }
    }

    if (negative_sign == 1) {
        final_Result = final_Result * -1;
    }
    
    return final_Result;
}

int power_Function(int num, int power) {
    while (power >= 1) {
        if (power == 1) {
            //printf("The returning number is %i\n", num);
            return num;
        } else {
            num = num * 10;
            //printf("The current number is %i\n", num);
            power--;
        }
    }
}
