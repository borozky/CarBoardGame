/******************************************************************************
** Student name: 	Joshua Orozco
** Student number: 	s3485376
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

void playGame()
{
    char choice[10];
    int chosenBoardNumber = 0;
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    int playerPosX; /* 0 - 9 */
    int playerPosY; /* 0 - 9 */
    char playerDirection[5]; /* north, south, east, west */

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
        scanf("%s%d", choice, &chosenBoardNumber);
        printf("\nYour input: %s\n", choice);
        printf("\nChosen board number:%d\n", chosenBoardNumber);

        if (strcmp("load", choice) == 0 && (chosenBoardNumber == 1 || chosenBoardNumber == 2)) {
            if (chosenBoardNumber == 1) {
                loadBoard(board, BOARD_1);
            } 
            else if (chosenBoardNumber == 2) {
                loadBoard(board, BOARD_2);
            }
            displayBoard(board, NULL);
            continue;
        }


        printf("Invalid input\n");



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
