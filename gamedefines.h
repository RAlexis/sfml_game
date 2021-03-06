#ifndef _GAME_DEFINES_H
#define _GAME_DEFINES_H

#define APP_NAME "SFML Game"
#define APP_FRAMESPERSECOND 60
#define APP_WIDTH 800
#define APP_HEIGHT 600

#define DEG2RAD 3.14159f / 180.0f

enum Direction
{
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

enum PlayerState
{
    STATE_DEAD = 0,
    STATE_ALIVE
};

#endif