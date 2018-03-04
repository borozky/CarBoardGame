/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

void playGame()
{
    char choice[10];
    int chosenBoardNumber = 0;
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    /* INSTRUCTIONS */
    displayGameInstructions();
    printf("\n");
    printf("Press enter to continue...\n");


    /* TODO: Proceed when <enter> key is pressed */

    /**
     * This is some sample code using the functions provided.
     *
     * Note that NULL is passed as the "Player * player" parameter as there is
     * no player cell present on the board in this example.
     */
    initialiseBoard(board);
    displayBoard(board, NULL);


    /*
    loadBoard(board, BOARD_1);
    displayBoard(board, NULL);

    loadBoard(board, BOARD_2);
    displayBoard(board, NULL);
    */


    /* TODO: GAME LOOP */
    do {

        printf("Enter your choice: ");
        gets(choice);
        printf("Your input:%s\n", choice);

        if (chosenBoardNumber == 1 || chosenBoardNumber == 2) {
            /* TODO: load and quit only allowed */
        }
        else {
            /* TODO: rest of the commands becomes available */
        }

        if (strcmp("load 1", choice) == 0) {
            loadBoard(board, BOARD_1);
            displayBoard(board, NULL);
        }
        else if (strcmp("load 2", choice) == 0) {
            loadBoard(board, BOARD_2);
            displayBoard(board, NULL);
        }

    } while (strcmp("quit", choice) != 0);


}


void displayGameInstructions() {
    printf("You can use the following commands to play the game\n");
    printf("load <g>\n");
    printf("\tg: number of the game board to load\n");
    printf("init <x>, <y>, <direction>\n");
    printf("\tx: horizontal position of the car on the board (between 0 & 9)\n");
    printf("\ty: vertical position of the car on the board (between 0 & 9)\n");
    printf("\tdirection: direction of the car's movement (north, east, south, west)\n");
    printf("forward (or f)\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n");

}
