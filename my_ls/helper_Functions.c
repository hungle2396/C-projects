#include <stdio.h>
#include "my_ls.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

/* Swapping nodes */
file_Node *swap(file_Node *ptr1, file_Node *ptr2)
{
    file_Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

/* Comparing strings */
int my_strcmp(char *string_1, char *string_2)
{
    while (*string_1 == *string_2)
    {
        if (*string_1 == '\0' || *string_2 == '\0')
        {
            break;
        }
        string_1++;
        string_2++;
    }

    if (*string_1 == '\0' && *string_2 == '\0')
    {
        return 0;
    }
    else if (*string_1 > *string_2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void open_subDirectory(Options *option, char *av) {
    struct dirent *sd;
    DIR *dir;
    dir = opendir(av);

    while ((sd = readdir(dir)) != NULL)
    {
        if ((my_strcmp(sd->d_name, ".") == 0 || my_strcmp(sd->d_name, "..") == 0)
        && option->a == 0)
        {
            continue;
        }
        else
        {
            printf("%s  ", sd->d_name);
        }
    }
    printf("\n\n");

    closedir(dir);
}

/* Printing regular files or directories */
void sub_Directories(Options *option, file_Node *Head, char *av)
{
    int file_Exist = 0;
    //DIR *dir;
    //struct dirent *sd;
    file_Node *temp = Head;

    // 1. Going through each node and compare to the file Name
    while (temp != NULL)
    {
        // 2. Check if node's file name and file's name are equal
        if (my_strcmp(temp->file_Name, av) == 0)
        {
            // 3. Check what type of file it is
            // 3.1 If the file is a regular file, just print it out
            if (temp->file_Type == 8)
            {
                printf("%s  ", temp->file_Name);
            }

            // 3.2 If the file is a directory
            if (temp->file_Type == 4)
            {
                printf("%s:\n", temp->file_Name);

                open_subDirectory(option, av);
                
            }
            file_Exist = 1;
        }
        temp = temp->next;
    }

    if (my_strcmp(av, "/tmp") == 0 || my_strcmp(av, "/tmp/") == 0) {
        open_subDirectory(option, av);
        file_Exist = 1;
    }

    if (temp == NULL && file_Exist == 0)
    {
        printf("The file or directory: '%s' does not exist!\n", av);
    }
}

/* Alphabet Sort */
void alphabetSort(file_Node **Head, int file_Counter)
{
    file_Node **h; 
    int i, j, swapped; 
  
    i = 0;
    while (i <= file_Counter)
    {
        h = Head; 
        swapped = 0; 

        j = 0;
        while (j < file_Counter - i - 1)
        {
            file_Node *p1 = *h; 
            file_Node *p2 = p1->next; 
  
            if (my_strcmp(p1->file_Name, p2->file_Name) == 1)
            { 
                // update the link after swapping
                *h = swap(p1, p2); 
                swapped = 1; 
            } 
            h = &(*h)->next; 

            j++;
        }
        // break if the loop ended without any swap 
        if (swapped == 0)
        {
            break; 
        }
        i++;
    }
}

/* Sort the nodes for base don time modificaiton (-t) or at option */
void time_Sort(file_Node **Head, int file_Counter)
{
    file_Node **h; 
    int i, j, swapped; 
  
    i = 0;
    while (i <= file_Counter)
    {
        h = Head; 
        swapped = 0; 

        j = 0;
        while (j < file_Counter - i - 1)
        {
            file_Node *p1 = *h;
            file_Node *p2 = p1->next;
  
            if (p1->time_Msec < p2->time_Msec)
            {
                // update the link after swapping
                *h = swap(p1, p2);
                swapped = 1;
            }
            else if (p1->time_Msec == p2->time_Msec)
            {
                if (p1->time_Nano < p2->time_Nano)
                {
                    *h = swap(p1, p2);
                }
                else if (p1->time_Nano == p2->time_Nano)
                {
                    if (my_strcmp(p1->file_Name, p2->file_Name) == 1)
                    {
                        *h = swap(p1, p2);
                    }
                }
                swapped = 1;
            }
  
            h = &(*h)->next; 

            j++;
        }
        // break if the loop ended without any swap 
        if (swapped == 0) {
            break; 
        }
        i++;
    }
} 

/* Creating a node */
file_Node *Create_file_Node(char *file_Name, int file_Type, __time_t time_Msec, long time_Nano)
{
    // 1. Malloc a node
    file_Node *File = (file_Node *)malloc(sizeof(file_Node));

    // 2. set the value info to the file Node
    File->file_Name = file_Name;
    File->file_Type = file_Type;
    File->time_Msec = time_Msec;
    File->time_Nano = time_Nano;

    // 3. Set the next memory address pointing to, to NULL
    File->next = NULL;

    return File;
}

file_Node *Create_file_LinkedList(Options *option, int *pfile_Counter, DIR *dir)
{
    file_Node *Head = NULL;
    file_Node *temp = NULL;
    file_Node *p = NULL;
    struct dirent *sd;
    struct stat buffer;

    if (dir == NULL)
    {   // 3. Check for error
        printf("The directory for T can't be open!\n");
    }

    while ( (sd = readdir(dir)) != NULL)
    {   // 4. Going through each dictorory or file
        stat(sd->d_name, &buffer);
        
        if ((my_strcmp(sd->d_name, ".") == 0 || my_strcmp(sd->d_name, "..") == 0) && option->a == 0)
        {
            continue;
        }
        else
        {
            temp = Create_file_Node(sd->d_name, sd->d_type, buffer.st_mtim.tv_sec, buffer.st_mtim.tv_nsec); // 5. Malloc a file node struct

            if (Head == NULL)
            {   // 5.1 if list is currently empty, then make the temp as first node
                Head = temp;
            }
            else
            {   // 5.2 connecting Head to second node and above
                p = Head;
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
                }
            *pfile_Counter = *pfile_Counter + 1;        // 5.3 Keep count how many nodes there are for bubbleSort function later
        }
    }

    return Head;
}

/* print out the nodes' dir/file names */
void printList(file_Node *Head)
{
    file_Node *Temporary = Head;

    // while the head and node's memory address pointing to is not NULL
    while (Temporary != NULL)
    {
        printf("%s  ", Temporary->file_Name);
        Temporary = Temporary->next;
    }
}

/* Free all the node structure that were malloced */
void freeList(file_Node *Head)
{
    file_Node *tmp;

    while (Head != NULL)
    {
        tmp = Head;
        Head = Head->next;
        free(tmp);
    }
}