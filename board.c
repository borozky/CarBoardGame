/******************************************************************************
** Student name: 	Joshua Orozco
** Student number: 	s3485376
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

    /* all cells are empty */
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

    /* basically clones the boardToLoad */
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

        /* Remove the player from the board, then add the player again */
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
    Position nextPosition;
    
    if (player == NULL) {
        return OUTSIDE_BOUNDS; /* WHAT? */
    }

    /**
     * OUTSIDE BOUNDS
     * - nextPosition cannot be -1, -2, -3, ...
     * - also nextPosition cannot be 10, 11, 12, ...
     */
    nextPosition = getNextForwardPosition(player);
    if (nextPosition.x < 0 || 
        nextPosition.x > BOARD_WIDTH - 1 || 
        nextPosition.y < 0 || 
        nextPosition.y > BOARD_HEIGHT - 1) {
        return OUTSIDE_BOUNDS;
    }

    /* BLOCKED */
    if (board[nextPosition.y][nextPosition.x] == BLOCKED) {
        return CELL_BLOCKED;
    }

    /* Update player's position */
    player->position.x = nextPosition.x;
    player->position.y = nextPosition.y;
    return PLAYER_MOVED;
}


void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    int x = 0, row = 0, col = 0, posX = -1, posY = -1;

    if (player != NULL) {
        posX = player->position.x;
        posY = player->position.y;
    }

    /* FIRST ROW */
    printf("| |");
    for (x = 0; x < BOARD_WIDTH; x++) {
        printf("%d|", x);
    }
    printf("\n");


    /* Next 9 rows */
    for (row = 0; row < BOARD_HEIGHT; row++) {

        /* FIRST COLUMN */
        printf("|%d|", row);

        /* Next 9 columns */
        for (col = 0; col < BOARD_WIDTH; col++) {
            if (board[row][col] == BLOCKED) {
                printf("*");
            }
            else if (posX > -1 && posY > -1 && posX == col && posY == row) {
                displayDirection(player->direction);
            }
            else if (board[row][col] == EMPTY) {
                printf(" ");
            }

            printf("|");
        }
        printf("\n");
    }
}
