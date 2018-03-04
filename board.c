/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int row = 0, col = 0;

    for (row = 0; row < BOARD_HEIGHT; row++) {
        for (col = 0; col < BOARD_WIDTH; col++) {
            board[row][col] = EMPTY;
        }
    }
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
    int row = 0, col = 0;
    for (row = 0; row < BOARD_HEIGHT; row++) {
        for (col = 0; col < BOARD_WIDTH; col++) {
            board[row][col] = boardToLoad[row][col];
        }
    }
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    int posX, posY, row = 0, col = 0;

    posX = position.x;
    posY = position.y;

    /**
     * Corners located at
     * 
     * (0, 0)
     * (BOARD_WIDTH - 1 = 9, 0)
     * (BOARD_WIDTH - 1 = 9, BOARD_HEIGHT - 1 = 9)
     * (0, BOARD_HEIGHT - 1 = 9)
     */
    if (posX >= 0 && posY >= 0 && posX < BOARD_WIDTH && posY < BOARD_HEIGHT && board[posY][posX] == EMPTY) {

        /* Remove the player from the board, then add the player again*/
        for (row = 0; row < BOARD_HEIGHT; row++) {
            for (col = 0; col < BOARD_WIDTH; col++) {
                if (board[row][col] == PLAYER) {
                    board[row][col] = EMPTY;
                }
            }
        }
        board[posY][posX] = PLAYER;
        return TRUE;
    }

    return FALSE;

}


PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
    if (player == NULL) {
        return OUTSIDE_BOUNDS; /* TODO: Wat? */
    }

    Position nextPosition = getNextForwardPosition(player);
    placePlayer(board, nextPosition);

    return PLAYER_MOVED;
}


void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    int x = 0, row = 0, col = 0, posX = -1, posY = -1;

    if (player != NULL) {
        posX = player->position.x;
        posY = player->position.y;
    }

    printf("| |");
    for (x = 0; x < BOARD_WIDTH; x++) {
        printf("%d|", x);
    }
    printf("\n");

    for (row = 0; row < BOARD_HEIGHT; row++) {
        printf("|%d|", row);
        for (col = 0; col < BOARD_WIDTH; col++) {
            if (board[row][col] == BLOCKED) {
                printf("*");
            }
            else if (posX > -1 && posY > -1 && posX == col && posY == row) {
                printf("P");
            }
            else if (board[row][col] == EMPTY) {
                printf(" ");
            }

            printf("|");
        }
        printf("\n");
    }
}
