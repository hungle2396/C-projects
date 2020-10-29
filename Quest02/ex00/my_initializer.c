#include <stdio.h>
#include <stdlib.h>

void my_initializer(int *nbr) {

    *nbr = 0;
}


int main() {
    int number = 5;

    my_initializer(&number);
    printf("%i", number);

    return 0;
}