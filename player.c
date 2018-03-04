/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
    /* TODO */
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /* TODO */
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
}
