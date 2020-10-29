#include <stdio.h>
#include <string.h>

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

int main() {

    char inputString[] = "AbCDe";
    char outputString[50];

    printf("Input: %s\n", inputString);

    printf("Output: %s\n", my_strrev(inputString));

    return 0;
}