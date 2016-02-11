#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "bullet.h"
//#include "gamedefines.h"

//std::vector<Bullet> bullets;

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

class Player
{
    public:
        Player(int _lives);
        ~Player();
        std::vector<Bullet> bullets;

        int GetPlayerInput();
        
        int GetLives()
        {
            return this->m_lives;
        }

        bool SetState(bool _state)
        {
            this->m_isAlive = _state;
        }

        bool IsAlive()
        {
            return this->m_isAlive;
        }

        void Update(int _moveInput);

        bool CanMoveToPoint(float _xVal, float _yVal);

        sf::Vector2f GetPosition()
        {
            return this->m_object.getPosition();
        }

        float GetRadius()
        {
            return this->m_object.getRadius();
        }

        bool CanMove()
        {
            return this->m_canMove;
        }

        sf::CircleShape m_object;

    private:
        int m_lives;
        bool m_isAlive;
        bool m_canMove;

};

#endif