#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#include "Utoa.h"
#include "Itoa.h"
#include "helper_functions.h"

char *my_strrev(char *str) {
    char temp;     // declare a temp character that will be use in the swap function

    char *start_Pointer = NULL; // declare a start pointer to use in swap function
    char *end_Pointer = NULL;  // declare an end pointer to use in the swap function

    start_Pointer = str;    // set the start pointer of start pointer = to pointer of str
    end_Pointer = str + strlen(str) - 1; // set the end pointer to str + the length of the characters inside the string - 1


    // swap the end pointer and start pointer's elements function
    while (end_Pointer > start_Pointer) {
        temp = *start_Pointer;
        *start_Pointer = *end_Pointer;
        *end_Pointer = temp;

        // update the pointers by increasement the start Pointer to next element, and decrement the end pointer to the element before the current element
        start_Pointer++;
        end_Pointer--;
    }
    
    // return the original's memory address that has the modified elements
    return str;
}

void my_strcpy(char *Result, char *Input, int *j) {
	int i = 0;

	int temp_Number = *j;

	while (Input[i] != '\0') {
		Result[temp_Number] = Input[i];
		//printf("%c ", Result[temp_Number]);
		//printf("current j is %i\n", temp_Number);
		i++;
		temp_Number++;
	}
	temp_Number--;
	*j = temp_Number;
}

// Count the string length
int my_strlen(char *str) {
    int index = 0;
    int Counter = 0;

    while (str[index] != '\0') {
        if (str[index] == '%') {
            index++;
            if (str[index] == 'd') {
                Counter += 10;
            } else if (str[index] == 'u' || str[index] == 'o' || str[index] == 'x' || str[index] == 'p') {
                Counter += 16;
            } else if (str[index] == 'c' || str[index] == 's') {
                Counter += 1;
            }
        } else {
            Counter++;
        }
        index++;
    } 

    return Counter;
}