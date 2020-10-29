#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(int ac, char **av) {           

    if (av[1] == 0 || av[2] == 0) {
        return 0;
    }

    int x = atoi(av[1]); // converting the argument string 1 to an integer
    int y = atoi(av[2]); // converting the argument string 2 to an integer

    // Element counters
    int i = 1;
    int j = 1;

    // Outter loop that check for the rows 
    while (i <= y) {
        // Inner loop that check for the columns                   
        if (i == 1) {                                                  
            while (j < x) {                                        
            // Condition for the first row
                if (j == 1) {
                    printf("o");
                    j++;
                } else if (j != 1) {
                    printf("-");
                    j++;
                }
            }

            if (j == x) {
                printf("o\n");
                // reset j back to 0
                j = 1;
            }
        } else if (i == y) {
            while (j < x) {
            // Condition for the first row
                if (j == 1) {
                    printf("o");
                    j++;
                } else if (j != 1) {
                    printf("-");
                    j++;
                }
            }

            if (j == x) {
                printf("o\n");
            }
        } else {
            while (j < x) {
            // Condition for the first row
                if (j == 1) {
                    printf("|");
                    j++;
                } else if (j != 1) {
                    printf(" ");
                    j++;
                }
            }

            if (j == x) {
                printf("|\n");
                // reset j back to 0
                j = 1;
            }
        }

        i++;
    }

    return 0;
}
*/

int main(int ac, char **av)
{
    if (av[1] == 0 && av[2] == 0) // // 1. fixed the av[1] == 0
    {
        return 0;
    }

    int column = atoi(av[1]);
    int row = atoi(av[2]);
    int column_runner = 1, row_runner = 1; // 2. error here because column_runner didn't assign to 1

// Main while loop for each row until the row_runner > the input row param
    while (row_runner <= row)
    {
        if (row_runner == 1)
        {
            while (column_runner <= column)
            {
                if (column_runner == 1)
                {
                    printf("o");
                    //column_runner++;
                } else if (column_runner < column)
                {
                    printf("-");
                    //column_runner++;
                } else if (column_runner == column)
                {
                    printf("o");
                    //column_runner++;
                }
                column_runner++;
            }
            printf("\n");
            column_runner = 1;
            row_runner++;
        }

        while (row_runner < row)
        {
            while (column_runner <= column)
            {
                if (column_runner == 1)
                {
                    printf("|");
                    column_runner++;
                }

                if (column_runner < column)
                {
                    printf(" ");
                    column_runner++;
                }
                if (column_runner == column)
                {
                    printf("|");
                    column_runner++;
                }
            }
            printf("\n");
            column_runner = 1;
            row_runner++;
        }

        if (row_runner == row)
        {
            while (column_runner <= column)
            {
                if (column_runner == 1)
                {
                    printf("o");
                    column_runner++;
                }
                if (column_runner < column)
                {
                    printf("-");
                    column_runner++;
                }
                if (column_runner == column)
                {
                    printf("o");
                    column_runner++;
                }
            }
            printf("\n");
            column_runner = 1;
            row_runner++;
        }
    }
}