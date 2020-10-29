#include <stdio.h>

/* Finds the last occurrence of the entire string str2 (not including the terminating null character) which appears in the string str1. Returns a pointer to the last occurrence of str2 in str1. If no match was found, then a null pointer is returned. If str2 points to a string of zero length, then the argument str1 is returned.

It should be prototyped:

char *my_strstr(char *str1, char *str2);

*/

char *my_strstr(char *param_1, char *param_2);

int main() {

    char string_A[128] = "";
    char string_B[128] = "";

    char *Result = my_strstr(string_A, string_B);

    printf("The result is: %s\n", Result);

    return 0;
}


// Function to implement strstr() function
char *my_strstr(char *param_1, char *param_2) {

    int i = 0;
    int j = 0;
    
    // 1. Check if string B is empty
    if (param_2[j] == '\0') {
        //printf("String A and B are empty!\n");
        return param_1;
    } 

    // 2. Going to each character in string 1 to match the first similar char in string 2
    i = 0; j = 0;
    while (param_1[i] != '\0') {
        if (param_1[i] == param_2[j]) {
            return param_1 + i;
        } else {
            i++;
        }
    }

    // 3. Return null if none of the character in string 1 matches string 2 first character
	return NULL;
}
