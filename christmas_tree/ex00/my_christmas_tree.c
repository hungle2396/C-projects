#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Create a program that print out a christmas tree based on the user input */

void christmas_Tree(int Trees);
int amount_of_Stars(int Number);
bool even_odd_Checker(int Number);
void print_Leaves(int numberof_Sets, int total_of_Stars);
void print_Trunk(int total_Trees, bool even_Odd, int total_of_Stars);

int main(int argc, char **argv) {
    // Convert string to int
    int user_Input = atoi(argv[1]);

    christmas_Tree(user_Input);

    return 0;
}

void christmas_Tree(int setof_Trees) {
    int total_Stars;
    bool even_Result;

    // 1. count on how many stars are needed
    total_Stars = amount_of_Stars(setof_Trees);

    printf("total stars %i\n", total_Stars);
    // 2 printing out the leaves
    print_Leaves(setof_Trees, total_Stars);
    
    // 3. Check if the user input is even or odd
    even_Result = even_odd_Checker(setof_Trees);
    
    // 4. printing out the trunk
    print_Trunk(setof_Trees, even_Result, total_Stars);
}

void print_Leaves(int numberof_Sets, int total_of_Stars) {
    int total_Row, current_Row, Set, decrement_Set, duplicate_Set, set_Row, current_Space, current_Stars, Counter, numberof_Stars, current_Tree, total_Spaces, base_Row;

    current_Tree = 1, current_Row = 1, Set = 0, decrement_Set = 1, duplicate_Set = 2, set_Row = 3, base_Row = 2, total_Row = 4, total_Spaces = total_of_Stars / 2;
    
    while (current_Tree <= numberof_Sets) {
        while (current_Row <= total_Row) {
            // 2.2 Printing out the Space for the current row
            // Reset the space back to 1 for next row
            current_Space = 1;
            while (current_Space <= total_Spaces) {
                printf(" ");
                current_Space++;
            }

            // 2.3 Printing out the Stars for the current row
            current_Stars = 1;
            numberof_Stars = (current_Row * 2) - 1;
            while (current_Stars <= numberof_Stars) {
                printf("*");
                current_Stars++;
            }

            // Go to the next row 
            printf("\n");

            // 2.4 Go to next set if the current_Row is equal to total_Row
            if (current_Row == total_Row) {
                set_Row++;
                Set++;
                current_Row = current_Row - decrement_Set;
                total_Row = current_Row + set_Row;
                total_Spaces = total_Spaces + decrement_Set;
                
                if (Set == duplicate_Set) {
                    decrement_Set++;
                    Set = 0;
                }
                break;    
            }
            current_Row++;
            total_Spaces--;
        }
        current_Tree++;
    }
}

void print_Trunk(int total_Trees, bool even_Odd, int total_of_Stars) {
    int current_Tree, current_Space, current_Pipe, total_Pipes, base_Number, decrement_Spaces, total_of_Spaces;

    total_of_Spaces = total_of_Stars / 2;
    total_Pipes = total_Trees;

    // if the number is even
    if (even_Odd == true) {
        base_Number = 2;

        // calculate the total space - number from user input
        while (base_Number <= total_Trees) {
            decrement_Spaces = (base_Number / 2) - 1;
            base_Number = base_Number + 2;
        }
    } else {
        base_Number = 1;

        // calculate the total space - number from user input
        while (base_Number <= total_Trees) {
            decrement_Spaces = (base_Number / 2);
            base_Number = base_Number + 2;
        }
    }
        
        
        
    total_of_Spaces = total_of_Spaces - decrement_Spaces;
    
    // printing out the spaces and pipes
    current_Tree = 1;
    while (current_Tree <= total_Trees) {
        // printing the spaces
        current_Space = 1;
        while (current_Space <= total_of_Spaces) {
            printf(" ");
            current_Space++;
        }

        // printing the pipes
        current_Pipe = 1;
        while (current_Pipe <= total_Pipes) {
            printf("|");
            current_Pipe++;
        }
    
        printf("\n");
        current_Tree++;
    } 
}

int amount_of_Stars(int Sets) {
    int Counter = 1;
    int total_Stars = 1;
    int additional_Stars = 6;
    int duplicate_Sets = 2;
    int set_Counter = 0;

    while (Counter <= Sets) {                                          // Counter = 1
        if (set_Counter <= duplicate_Sets) {                           // 
            total_Stars = total_Stars + additional_Stars;
            set_Counter++;
        }

        if (set_Counter == duplicate_Sets) {
            additional_Stars = additional_Stars + 2;
            set_Counter = 0;
        }

        Counter++;
    }
    printf("total stars is %i\n", total_Stars);
    return total_Stars;
}

bool even_odd_Checker(int Number) {
    bool Result; 

    if (Number % 2 == 0) {
        Result = true;
    } else {
        Result = false;
    }

    return Result;
}