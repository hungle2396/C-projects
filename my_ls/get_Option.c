#include <stdlib.h>
#include "my_ls.h"

Options *init_option() {
    Options* option = (Options *) malloc(sizeof(Options));

    option->a = 0;
    option->t = 0;

    return option;
};

void set_Option(Options *option, char *string) {
    int index = 0;

    while (string[index] != '\0') {
        if (string[index] == 'a') {
            option->a = 1;
        } else if (string[index] == 't') {
            option->t = 1;
        }
        index += 1;
    }

}

int is_Option(char *string) {
    
    if (string[0] == '-') {
        return 1;
    } else {
        return 0;
    }
} 

Options *get_Option(int ac, char **av) {
    int index = 0;

    // 1. Create a struct Option malloc 
    Options *option = init_option();

    while (index < ac) {
        if (is_Option(av[index]) == 1) {
            set_Option(option, av[index] + 1);
        }
        index = index + 1;
    }

    return option;
}