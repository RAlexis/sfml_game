#ifndef _GAME_DEFINES_H
#define _GAME_DEFINES_H

#define WIDTH 800
#define HEIGHT 600

#define PLAYER_SPEED_UP -2.5
#define PLAYER_SPEED_DOWN 2.5
#define PLAYER_SPEED_LEFT -2.5
#define PLAYER_SPEED_RIGHT 2.5

enum PlayerInput
{
    INPUT_NULL = -1,

    MOVE_UP = 0,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP_LEFT,
    MOVE_UP_RIGHT,
    MOVE_DOWN_LEFT,
    MOVE_DOWN_RIGHT,

    SPAWN_BULLET
};

enum PlayerState
{
    STATE_DEAD = 0,
    STATE_ALIVE
};

#endif