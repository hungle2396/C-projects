#include <stdio.h>
#include <stdlib.h>

/* Write a function named hidenp that takes two strings and return 1
- If the first string is hidden in the second one,
- otherwise returns 0 followed by a newline

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to find
each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.
*/

int hidenp(char *param_1, char *param_2);

int main() {
    int Result;
    char string_One[128] = "";
    char string_Two[128] = "long string ?ddl";

    Result = hidenp(string_One, string_Two);

    printf("%i\n", Result);

    return 0;
}

int hidenp(char *param_1, char *param_2) {

    int i, j;

    // 1. go through each character in string 1
    i = 0, j = 0;
    while (param_1[i] != '\0') {
        printf("Test 1, current character in string 1 is %c\n", param_1[i]);
        // 2. Go through each character in string 2 
        while (param_2[j] != '\0') {
            printf("Test 2, current character in string 2 is %c\n", param_2[j]);
            // 3. Compare to see if string 2 have all characters from string 1
            if (param_1[i] == param_2[j]) {
                printf("Test 3, current character %c in string 2 matches with %c in string 1\n", param_2[j], param_1[i]);
                break;
            } else {
                j++;
            }
        }

        // if string 2 reaches to null char, return 0 
        // string 2 didn't have all the chars from string 1
        if (param_2[j] == '\0') {
            return 0;
        }
        i++;
    }

    // String 1 reaches to the null char
    // String 2 has all the chars from string 1
    return 1;
}