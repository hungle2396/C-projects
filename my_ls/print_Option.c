#include <stdio.h>
#include "my_ls.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void miscellaneous_Option(Options *option, int ac, char *av)
{
    int file_Counter = 0;
    int *pfile_Counter = &file_Counter;
    file_Node *Head = NULL;
    DIR *dir;
    dir = opendir(".");
    Head = Create_file_LinkedList(option, pfile_Counter, dir);

    if (ac == 1 || my_strcmp(av, ".") == 0)
    {
        alphabetSort(&Head, file_Counter);
        printList(Head);
    }
    else
    {
        sub_Directories(option, Head, av);
    }
    freeList(Head);
    closedir(dir);
}

void print_Option_AT(Options *option, int ac, char *av, int index)
{
    int file_Counter = 0;
    int *pfile_Counter = &file_Counter;
    file_Node *Head = NULL;
    DIR *dir;
    dir = opendir(".");
    Head = Create_file_LinkedList(option, pfile_Counter, dir);
    
    // 1. my_ls -at and my_ls -a -t option only
    if ((ac == 2 && my_strcmp(av, "-at") == 0) ||
    (ac == 3 && index >= 2 && (my_strcmp(av, "-a") == 0 || my_strcmp(av, "-t") == 0))) {
        alphabetSort(&Head, file_Counter);
        time_Sort(&Head, file_Counter);
        printList(Head);
    // 2. my_ls -at Dir option
    } else if ((ac >= 3 && index >= 2 && my_strcmp(av, "-at") != 0) ||
    (ac >= 3 && index >= 3 && (my_strcmp(av, "-a") == 0 || my_strcmp(av, "-t") == 0))) {
        sub_Directories(option, Head, av);
    }

    freeList(Head);
    closedir(dir);
}

void print_Option_T(Options *option, int ac, char *av)
{
    int file_Counter = 0;
    int *pfile_Counter = &file_Counter;
    file_Node *Head = NULL;
    DIR *dir;
    dir = opendir(".");
    Head = Create_file_LinkedList(option, pfile_Counter, dir);

    if (ac > 2 && my_strcmp(av, "-t") != 0)
    {
        sub_Directories(option, Head, av);
    }
    else if (ac == 2)
    {
        time_Sort(&Head, file_Counter);
        printList(Head);
    }

    freeList(Head);

    closedir(dir);
}

void print_Option_A(Options *option, int ac, char *av)
{
    int file_Counter = 0;
    int *pfile_Counter = &file_Counter;
    file_Node *Head = NULL;
    DIR *dir;
    dir = opendir(".");
    Head = Create_file_LinkedList(option, pfile_Counter, dir);

    if (ac > 2 && my_strcmp(av, "-a") != 0)
    {
        sub_Directories(option, Head, av);
    }
    else if (ac == 2)
    {
        alphabetSort(&Head, file_Counter);
        printList(Head);
    }
    freeList(Head);
    closedir(dir);
}

void print_Option(Options *option, int ac, char **av)
{
    int index = 1;
    // 1. Option my_ls -a
    if (option->a == 1 && option->t == 0)
    {
        while (index < ac)
        {
            print_Option_A(option, ac, av[index]);
            index += 1;
        }
    }
    // 2. Option my_ls -t
    else if (option->a == 0 && option->t == 1)
    {
        while (index < ac)
        {
            print_Option_T(option, ac, av[index]);
            index += 1;
        }
    }
    // 3. Option my_ls -at or my_ls -a -t
    else if (option->a == 1 && option->t == 1)
    {
        while (index < ac)
        {   
            print_Option_AT(option, ac, av[index], index);
            index += 1;
        }
    }
    // 4. my_ls and my_ls "." options
    else if ((option->a == 0 && option->t == 0 && ac == 1) || (ac == 2 && my_strcmp(av[1], ".") == 0))
    {
        miscellaneous_Option(option, ac, av[index]);
    }
    // 5. my_ls Dir1 Dir2 option
    /*else if (ac == 2 && my_strcmp(av[1], "/tmp/") == 0)
    {
        miscellaneous_Option(option, ac, av[index]);
    } */
    else if (ac > 1)
    {
        while (av[index] != NULL)
        {
            miscellaneous_Option(option, ac, av[index]);
            index++;
        }
    }
}