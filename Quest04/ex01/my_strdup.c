#include <stdio.h>
#include <stdlib.h>
#include <String.h>

/* reproduce the behavior of strdup from man strdup 

It should be prototyped:

char *my_strdup(char *src);

*/

char *my_strdup(char *src);

int main() {
    char String[] = "";

    char *Result = my_strdup(String); 
    
    printf("%s\n", strdup(String));
    printf("%s", Result);
    
    return 0;
}

char *my_strdup(char *src) {
    
    char *copied_String = src;
    char *result_String = NULL;
    int i = 0;
    int size; 

    // Finding out the length of the String
    while (copied_String[i] != '\0') {
        i++;
    }

    if (copied_String[i] == '\0') {
        i++;
        size = i;
        
        //reset i  back to 0.
        i = 0;
    }

    // Create a malloc that contain the characters in the string
    result_String = (char *) malloc(size * sizeof(char));
    
    // looping each characters from the original string to the malloc array
    if (result_String != NULL) {
        while (i < size) {
            result_String[i] = copied_String[i];
            i++;
        }
    }
    

    return result_String;
}
