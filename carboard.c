/******************************************************************************
** Student name: 	Joshua Orozco
** Student number: 	s3485376
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main(void)
{
    int choice = 0;

    do {
        showMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You have chosen to play the game"); 
            playGame();
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

        printf("\nInvalid input\n");
        choice = 0;

    } while (choice < 1 || choice > 3);

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
    printf("Name: %s\n", STUDENT_NAME);
    printf("No: %s\n", STUDENT_ID);
    printf("%s\n", STUDENT_EMAIL);
    printf("------------------------------------\n");
}
