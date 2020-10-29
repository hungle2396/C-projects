#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Create a program called my_cat which does the same thing as the system's cat command-line.
*/

int main(int argc, char **argv) {
    FILE *file_Pointer = NULL;
    char Character;
    int i;

    // 1. check how many files are being input
    i = 1;
    while (i < argc) {
        // 2. open the current file to read
        file_Pointer = fopen(argv[i], "r");
        
        // 3. Loop and print each character in the current file
        while ((Character = fgetc(file_Pointer)) != EOF) {
            printf("%c", Character);
        }

        printf("\n");
        // go to the next file
        i++;
    }

    fclose(file_Pointer);
    file_Pointer = NULL;

    return 0;
};

