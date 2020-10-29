#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

typedef struct Options
{
    int a;
    int t;
} Options;

typedef struct file_Node
{
    char *file_Name;
    int file_Type;
    __time_t time_Msec;
    long time_Nano;
    struct file_Node *next;
} file_Node;

/* get_Option.c file */
Options *get_Option(int ac, char **av);
Options *init_option();
void set_Option(Options *option, char *string);
int is_Option(char *string);

/* print_Option.c file */
void miscellaneous_Option(Options *option, int ac, char *av);
void print_Option_A(Options *option, int ac, char *av);
void print_Option_T(Options *option, int ac, char *av);
void print_Option_AT(Options *option, int ac, char *av, int index);

/* helper_Functions.c file */
file_Node *Create_file_Node(char *file_Name, int file_Type, __time_t time_Msec, long time_Nano);
file_Node *Create_file_LinkedList(Options *option, int *pfile_Counter, DIR *dir);
file_Node *Create_file_LinkedList_AT(int *pfile_Counter);
file_Node *swap(file_Node *ptr1, file_Node *ptr2);
void time_Sort(file_Node **Head, int file_Counter);
void alphabetSort(file_Node **Head, int file_Counter);
void sub_Directories(Options *option, file_Node *Head, char *av);
void print_Option(Options *option, int ac, char **av);
void printList(file_Node *Head);
void freeList(file_Node *head);
int my_strcmp(char *str1, char *str2);
void open_subDirectory(Options *option, char *av);
