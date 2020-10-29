#include <stdio.h>
#include <stdlib.h>


char *my_params_to_string(int argc, char **argv);

int main(int argc, char **argv) {
    

    // my_params_to_string(argc, argv);

    printf("The new array is %s\n", my_params_to_string(argc, argv));
 
    return 0;
}

char *my_params_to_string(int argc, char **argv) {

    int i = 0; 
    int j = 0;
    int k = 0;
    int size = 1;
    int extra_Size = ((argc - 2) * 2) - 1; 
    int lesser_argc = argc - 1;
    char *new_String = NULL;

    printf("Testing!\n");
    printf("There are %i bytes in this size\n", sizeof(size));

    // Finding the length of the characters in the arguments
    while (i != argc) {
        if (i >= 2) {
            while (argv[i][j] != '\0') {
                //printf("The current i is %i\n", i);
                //printf("The current character is %c\n", argv[i][j]);
                j++;
                printf("The current malloc_Length: %i\n", size);
                size++;
            }
        }
        j = 0;
        i++;
    }

    // Create a malloc for the new string
    new_String = (char *) malloc((size + extra_Size) * sizeof(char));

    // Putting the arguments in a malloc 
    for (i = 2; i < argc; i++) {
        printf("The current argument is %s\n", argv[i]);
        while (argv[i][j]) {
            // printf("The current character is %c\n", argv[i][j]);
            new_String[k] = argv[i][j];
            printf("The current character in new_String is %c\n", new_String[k]);
            k++;
            j++;
        }

        
        // reset j back to 0
        j = 0;
        
        printf("the current i is %i\n", i);
        printf("The current argc is %i\n", argc);
        if (i != lesser_argc) {
            // add the \ character in
            new_String[k] = '\\';
            printf("The current dash character is %c\n", new_String[k]);

            
            // adding the  'n'  character in the array
            k++;
            new_String[k] = 'n';
            printf("The current n character is %c\n", new_String[k]);
            k++;
        } else if (i == lesser_argc) {
            new_String[k] = '\0';
            return new_String;
        }
    }
}