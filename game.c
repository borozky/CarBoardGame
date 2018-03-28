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
    printf("Press enter to continue...");
    do {}
    while (getchar() != '\n');


    /* GAME LOOP */
    initialiseBoard(board);
    do {
        /* reload the whole board every time 
        to avoid compicated logic of tracking player's position */
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

        /* display board */
        if (playerLoaded == TRUE) {
            displayBoard(board, &player);
        } else {
            displayBoard(board, NULL);
        }
        

        printf("\n");
        printAcceptableCommands(&boardLoaded, &playerLoaded);
        printf("\n");
        

        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);

        /* read the first part of the command; new line is trimmed */
        commandToken = strtok(strtok(input, "\n"), " ");
        if (commandToken == NULL) {
            invalidInput();
            continue;
        }

        argsToken = strtok(NULL, " ");


        /* 'load' command */
        if (strcmp(COMMAND_LOAD, commandToken) == 0 && playerLoaded == FALSE) {
            boardLoaded = FALSE;

            if (argsToken == NULL) {} /* this line is just to avoid null-pointer errors */
            else if (strcmp("1", argsToken) == 0) {
                chosenBoardNumber = 1;
                boardLoaded = TRUE;
                continue;
            } 
            else if (strcmp("2", argsToken) == 0) {
                chosenBoardNumber = 2;
                boardLoaded = TRUE;
                continue;
            }
        }


        /* 'init' command */
        if (strcmp(COMMAND_INIT, commandToken) == 0 && boardLoaded == TRUE && playerLoaded == FALSE) {
            playerLoaded = FALSE;

            arg = strtok(argsToken, ",");

            /* position X */
            if (arg == NULL) {} /* this line is just to avoid null-pointer errors */
            else if (strcmp("0", arg) == 0) {
                positionX = 0;
            } 
            else if (atoi(arg) > 0 && atoi(arg) <= BOARD_WIDTH) {
                positionX = atoi(arg);
            }

            /* position Y */
            arg = strtok(NULL, ",");
            if (arg == NULL) {} /* this line is just to avoid null-pointer errors */
            else if (strcmp("0", arg) == 0) {
                positionY = 0;
            } 
            else if (atoi(arg) > 0 && atoi(arg) <= BOARD_HEIGHT) {
                positionY = atoi(arg);
            }

            /* direction */
            arg = strtok(NULL, ",");
            if (arg == NULL) {
                invalidInput();
                continue;
            } 
            else if (strcmp(DIRECTION_NORTH, arg) == 0) {
                direction = NORTH;
            } 
            else if (strcmp(DIRECTION_SOUTH, arg) == 0) {
                direction = SOUTH;
            }
            else if (strcmp(DIRECTION_EAST, arg) == 0) {
                direction = EAST;
            }
            else if (strcmp(DIRECTION_WEST, arg) == 0) {
                direction = WEST;
            } 
            else {
                invalidInput();
                continue;
            }

            /* intialize player */
            if (positionX < 0 || positionX > BOARD_WIDTH || positionY < 0 || positionY > BOARD_HEIGHT) {
                invalidInput();
                continue;
            }

            position.x = positionX;
            position.y = positionY;
            initialisePlayer(&player, &position, direction);
            if (placePlayer(board, player.position) == FALSE) {
                printf("ERROR: Cannot place player at (%d, %d)\n\n", player.position.x, player.position.y);
            } 
            else {
                playerLoaded = TRUE;
            }

            continue;
        }

        /* 'forward', 'turn_left' & 'turn_right' commands */
        if (playerLoaded == TRUE) {
            /* forward */
            if (strcmp(COMMAND_FORWARD, commandToken) == 0 || strcmp(COMMAND_FORWARD_SHORTCUT, commandToken) == 0) {
                switch (movePlayerForward(board, &player)) {
                    case CELL_BLOCKED:
                        printf("ERROR: Cannot move player forward. Player is blocked.\n\n");
                        break;
                    case OUTSIDE_BOUNDS:
                        printf("ERROR: Cannot move player outside of bounds\n\n");
                        break;
                    
                    /* movePlayerForward() updates player->position behind the scenes */
                    case PLAYER_MOVED:
                        break;
                    default:
                        break;
                }

                continue;
            }
            /* turn left */
            else if (strcmp(COMMAND_TURN_LEFT, commandToken) == 0 || strcmp(COMMAND_TURN_LEFT_SHORTCUT, commandToken) == 0) {
                turnDirection(&player, TURN_LEFT);
                continue;
            }
            /* turn right */
            else if (strcmp(COMMAND_TURN_RIGHT, commandToken) == 0 || strcmp(COMMAND_TURN_RIGHT_SHORTCUT, commandToken) == 0) {
                turnDirection(&player, TURN_RIGHT);
                continue;
            }
        }

        /* 'quit' command */
        if (strcmp(COMMAND_QUIT, commandToken) == 0) {
            break;
        }

        invalidInput();

    } while (TRUE);


}


void displayGameInstructions() {
    printf("You can use the following commands to play the game\n");
    printf("%s <g>\n", COMMAND_LOAD);
    printf("\tg: number of the game board to load\n");
    printf("%s <x>, <y>, <direction>\n", COMMAND_INIT);
    printf("\tx: horizontal position of the car on the board (between 0 & 9)\n");
    printf("\ty: vertical position of the car on the board (between 0 & 9)\n");
    printf("\tdirection: direction of the car's movement (%s, %s, %s, %s)\n", DIRECTION_NORTH, DIRECTION_SOUTH, DIRECTION_EAST, DIRECTION_WEST);
    printf("%s (or %s)\n", COMMAND_FORWARD, COMMAND_FORWARD_SHORTCUT);
    printf("%s (or %s)\n", COMMAND_TURN_LEFT, COMMAND_TURN_LEFT_SHORTCUT);
    printf("%s (or %s)\n", COMMAND_TURN_RIGHT, COMMAND_TURN_RIGHT_SHORTCUT);
    printf("%s\n", COMMAND_QUIT);
}


void invalidInput() {
    printf("\nERROR: Invalid input\n\n");
}


void printAcceptableCommands(Boolean *boardLoaded, Boolean *playerLoaded) {
    if (*boardLoaded == TRUE && *playerLoaded == TRUE) {
        printf("At this stage of the program, only 4 commands are acceptable:\n");
        printf("forward (or f)\n");
        printf("turn_left (or l)\n");
        printf("turn_right (or r)\n");
        printf("quit\n");
    } 
    else if (*boardLoaded == FALSE){
        printf("At this stage of the program, only two commands are acceptable:\n");
        printf("load <g>\n");
        printf("quit\n");
    }
    else if (*boardLoaded == TRUE && *playerLoaded == FALSE) {
        printf("At this stage of the program, only three commands are acceptable:\n");
        printf("load <g>\n");
        printf("init <x>,<y>,<direction>\n");
        printf("quit\n");
    }

}
