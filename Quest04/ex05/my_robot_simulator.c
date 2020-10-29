#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. {x: X, y: Y, bearing: Direction}
2. Direction orientation: (north, west, south, east)
3. Robot always start at (x: 0, y: 0, bearing: North);
4. Going south will increase Y, going north will decrease Y
5. Going east will increase X, going west will decrease X
6. The gris is unlimited, positions can be negative
*/

char *my_robot_simulator(char *param_1);

int main() {

    char string[20] = "RAARA";

    printf("The current string is %s\n", string);

    char *Result = my_robot_simulator(string);

    printf("The final instruction for the robot is %s\n", Result);

    return 0;
}


char *my_robot_simulator(char *param_1) {

    int i = 0, j = 0;
    int x = 0, y = 0;
    char character_x[10], character_y[10];
    char string_Direction[6];
    char Direction = 'N';
    char *Intro_String_1 = "{x: ";
    char *Intro_String_2 = ", y: ";
    char *Intro_String_3 = ", bearing: '";
    char *Intro_String_4 = "'}";

    char *Robot_Instruction = (char *) malloc(36 * sizeof(char));

    // going through each character in string param_1
    while (param_1[i] != '\0') {
        // if the character is R 
        if (param_1[i] == 'R') {
            if (Direction == 'N') {
                Direction = 'E';
            } else if (Direction == 'E') {
                Direction = 'S'; 
            } else if (Direction == 'S') {
                Direction = 'W';
            } else {
                Direction = 'N';
            }
        } else if (param_1[i] == 'L') {
            if (Direction == 'N') {
                Direction = 'W';
            } else if (Direction == 'W') {
                Direction = 'S';
            } else if (Direction == 'S') {
                Direction = 'E';
            } else {
                Direction = 'N';
            }
        } else if (param_1[i] == 'A') {
            // north = decrease in y
            if (Direction == 'N') {
                y--;
            // west = decrease in x
            } else if (Direction == 'W') {
                x--;
            // south = increase in y
            } else if (Direction == 'S') {
                y++;
            // if it's east then = increase in x
            } else {
                x++;
            }
        }
        i++;
    }
    /*
    printf("The current number of x is %i\n", x);
    printf("The current number of y is %i\n", y);
    printf("The direction is %c\n", Direction);
    */
    sprintf(character_x, "%i", x);
    //printf("The int x number converted to string is %s\n", character_x);

    sprintf(character_y, "%i", y);
    //printf("The int y number converted to string is %s\n", character_y);

    if (Direction == 'N') {
        strcpy(string_Direction, "north");
        //printf("The final direction string is %s\n", string_Direction);
    } else if (Direction == 'W') {
        strcpy(string_Direction, "west");
        //printf("The final direction string is %s\n", string_Direction);
    } else if (Direction == 'S') {
        strcpy(string_Direction, "south");
        //printf("The final direction string is %s\n", string_Direction);
    } else {
        strcpy(string_Direction, "east");
        //printf("The final direction string is %s\n", string_Direction);
    }

    strcat(Robot_Instruction, Intro_String_1);
    strcat(Robot_Instruction, character_x);
    strcat(Robot_Instruction, Intro_String_2);
    strcat(Robot_Instruction, character_y);
    strcat(Robot_Instruction, Intro_String_3);
    strcat(Robot_Instruction, string_Direction);
    strcat(Robot_Instruction, Intro_String_4);

    //printf("The current string is %s\n", Robot_Instruction);
    
    return Robot_Instruction;
};

