/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main(void)
{
    int choice = 0;
    showMenu();

    while (choice == 0 && choice <= 3) {
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You have chosen to play the game");
            return EXIT_SUCCESS;
        }

        if (choice == 2) {
            showStudentInformation();
            choice = 0;
            continue;
        }

        if (choice == 3) {
            printf("You have chosen to quit");
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
        

    
}

void showMenu() {
    printf("\n");
    printf("Welcome to Car Board\n");
    printf("--------------------\n");
    printf("1. Play game\n");
    printf("2. Show student's information\n");
    printf("3. Quit\n");
    printf("\n");
}


void showStudentInformation()
{
    printf("------------------------------------\n");
    printf("Name: Joshua Orozco\n");
    printf("No: s3485376\n");
    printf("s3485376@student.rmit.edu.au\n");
    printf("------------------------------------\n");
}
