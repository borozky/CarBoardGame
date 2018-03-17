/******************************************************************************
** Student name: 	Joshua Orozco
** Student number: 	s3485376
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"
#define PLAY_GAME 1
#define SHOW_STUDENT_INFO 2
#define QUIT 3

int main(void)
{
    int choice = 0;

    do {
        showMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case PLAY_GAME:
                playGame();
                break;
            case SHOW_STUDENT_INFO:
                showStudentInformation();
                break;
            case QUIT:
                return EXIT_SUCCESS;
            default:
                printf("\nInvalid input\n");
                break;
        }

        choice = 0;
    } while (1);

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
