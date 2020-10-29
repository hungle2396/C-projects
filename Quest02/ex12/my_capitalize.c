#include <stdio.h>

/* Create a my_capitalize function. Which takes a string as parameter and returns the capitalized version of it.
*/

char *my_capitalize(char *a);

int main() {

    char String[128] = "   Abc dEf !H1";

    printf("%s\n", String);

    char *Result = my_capitalize(String);  
    
    printf("%s\n", Result);
    return 0;
}


char *my_capitalize(char *a) {
    
    int i = 0;
    
    while (a[i] != 0) {
        // 1) First character that is between or equal to 'a' and 'z' that need to capitalize
        if (i == 0 && (a[i] >= 'a' && a[i] <= 'z')) {
            // Capitalize the character
            a[i] = a[i] - 32;
            i++;    
        } else if (i != 0 && (a[i] >= 'A' && a[i] <= 'Z')) {
            a[i] = a[i] + 32;
            i++;
        } else {
            i++;
        }
    }

    return a;
}