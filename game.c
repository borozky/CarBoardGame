/******************************************************************************
** Student name: 	Joshua Orozco
** Student number: 	s3485376
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"
#include "helpers.h"
#include <string.h>

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    char input[32];
    char *commandToken;
    char *argsToken;
    char *arg;
    
    int chosenBoardNumber = 0;

    int positionX = -1;
    int positionY = -1;
    Direction direction;

    Player player;
    Position position;

    Boolean boardLoaded = FALSE;
    Boolean playerLoaded = FALSE;

    /* INSTRUCTIONS */
    displayGameInstructions();
    printf("\n");
    printf("Press enter to continue...\n");
    readRestOfLine();


    initialiseBoard(board);

    /*
    loadBoard(board, BOARD_1);
    displayBoard(board, NULL);

    loadBoard(board, BOARD_2);
    displayBoard(board, NULL);
    */


    /* TODO: GAME LOOP */
    do {
        if (boardLoaded == TRUE) {
            switch (chosenBoardNumber) {
                case 1:
                    loadBoard(board, BOARD_1);
                    break;
                case 2:
                    loadBoard(board, BOARD_2);
                    break;
                default:
                    initialiseBoard(board);
                    break;
            }
        }

        if (playerLoaded == TRUE) {
            displayBoard(board, &player);
        } else {
            displayBoard(board, NULL);
        }

        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);

        /* read the first part of the command; new line is trimmed */
        commandToken = strtok(strtok(input, "\n"), " ");
        if (commandToken == NULL) {
            invalidInput();
            continue;
        }

        argsToken = strtok(NULL, " ");

        /* load */
        if (strcmp("load", commandToken) == 0) {
            boardLoaded = FALSE;

            if (argsToken == NULL) {
                invalidInput();
                continue;
            }

            if (strcmp("1", argsToken) == 0) {
                chosenBoardNumber = 1;
                boardLoaded = TRUE;
            } 
            else if (strcmp("2", argsToken) == 0) {
                chosenBoardNumber = 2;
                boardLoaded = TRUE;
            }
        }

        /* init */
        if (strcmp("init", commandToken) == 0 && boardLoaded == TRUE) {
            playerLoaded = FALSE;

            arg = strtok(argsToken, ",");

            /* position X */
            if (arg == NULL) {} 
            else if (strcmp("0", arg) == 0) {
                positionX = 0;
            } 
            else if (atoi(arg) > 0 && atoi(arg) <= 9) {
                positionX = atoi(arg);
            }

            /* position Y */
            arg = strtok(NULL, ",");
            if (arg == NULL) {} 
            else if (strcmp("0", arg) == 0) {
                positionY = 0;
            } 
            else if (atoi(arg) > 0 && atoi(arg) <= 9) {
                positionY = atoi(arg);
            }

            /* direction */
            arg = strtok(NULL, ",");
            if (arg == NULL) {
                invalidInput();
                continue;
            } 
            else if (strcmp("north", arg) == 0) {
                direction = NORTH;
            } 
            else if (strcmp("south", arg) == 0) {
                direction = SOUTH;
            }
            else if (strcmp("east", arg) == 0) {
                direction = EAST;
            }
            else if (strcmp("west", arg) == 0) {
                direction = WEST;
            } 
            else {
                invalidInput();
                continue;
            }

            /* intialize player */
            if (positionX < 0 || positionX > 9 || positionY < 0 || positionY > 9) {
                invalidInput();
                continue;
            }

            position.x = positionX;
            position.y = positionY;
            initialisePlayer(&player, &position, direction);
            if (placePlayer(board, player.position) == FALSE) {
                printf("Cannot place player at (%d, %d)\n", player.position.x, player.position.y);
            } 
            else {
                playerLoaded = TRUE;
            }

            continue;
        }

        if (playerLoaded == TRUE) {
            if (strcmp("forward", commandToken) == 0 || strcmp("f", commandToken) == 0) {
                switch (movePlayerForward(board, &player)) {
                    case CELL_BLOCKED:
                        printf("Cannot move player forward. Player is blocked.\n");
                        break;
                    case OUTSIDE_BOUNDS:
                        printf("Cannot move player outside of bounds\n");
                        break;
                    case PLAYER_MOVED:
                        break;
                    default:
                        break;
                }
            }
            else if (strcmp("turn_left", commandToken) == 0 || strcmp("l", commandToken) == 0) {
                turnDirection(&player, TURN_LEFT);
            }
            else if (strcmp("turn_right", commandToken) == 0 || strcmp("r", commandToken) == 0) {
                turnDirection(&player, TURN_RIGHT);
            }
        }

        if (strcmp("quit", commandToken) == 0) {
            break;
        }

    } while (TRUE);


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

void invalidInput() {
    printf("Invalid input\n");
}
