/******************************************************************************
** Student name: 	Joshua Orozco
** Student number: 	s3485376
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
    player->position.x = (*position).x;
    player->position.y = (*position).y;
    player->direction = direction;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    if (turnDirection == TURN_LEFT) {
        switch (player->direction) {
            case NORTH:
                player->direction = WEST;
                break;
            case SOUTH:
                player->direction = EAST;
                break;
            case EAST:
                player->direction = NORTH;
                break;
            case WEST:
                player->direction = SOUTH;
                break;
            default:
                break;
        }

    } 
    else if (turnDirection == TURN_RIGHT) {
        switch (player->direction) {
            case NORTH:
                player->direction = EAST;
                break;
            case SOUTH:
                player->direction = WEST;
                break;
            case EAST:
                player->direction = SOUTH;
                break;
            case WEST:
                player->direction = NORTH;
                break;
            default:
                break;
        }
    }
}

Position getNextForwardPosition(const Player * player)
{
    Position position;
    Direction direction = player->direction;
    
    int nextPosX = player->position.x;
    int nextPosY = player->position.y;

    switch (direction) {
        case NORTH:
            nextPosY -= 1;
            break;
        case EAST:
            nextPosX += 1;
            break;
        case WEST:
            nextPosX -= 1;
            break;
        case SOUTH:
            nextPosY += 1;
            break;
        default:
            break;
    }

    position.x = nextPosX;
    position.y = nextPosY;

    return position;
}

void updatePosition(Player * player, Position position)
{
    player->position.x = position.x;
    player->position.y = position.y;
}

void displayDirection(Direction direction)
{
    /*
    switch(direction) {
        case NORTH:
            printf(DIRECTION_ARROW_OUTPUT_NORTH);
            break;
        case SOUTH:
            printf(DIRECTION_ARROW_OUTPUT_SOUTH);
            break;
        case EAST:
            printf(DIRECTION_ARROW_OUTPUT_EAST);
            break;
        case WEST:
            printf(DIRECTION_ARROW_OUTPUT_WEST);
            break;
        default:
            break;
    }
    */
    switch(direction) {
        case NORTH:
            printf("^");
            break;
        case SOUTH:
            printf("v");
            break;
        case EAST:
            printf(">");
            break;
        case WEST:
            printf("<");
            break;
        default:
            printf("P");
            break;
    }
}
