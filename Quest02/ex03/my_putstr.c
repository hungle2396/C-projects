#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void my_putstr(char *str) {

    printf("\nThe string that was input: %s\n", str);

    return;
}

int main() {

    char *stringInput = "Bello World!";

    my_putstr(stringInput);

    return 0;
}