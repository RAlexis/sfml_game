#ifndef _PLAYER_H
#define _PLAYER_H

#include <math.h>
#include <SFML/Graphics.hpp>
#include "gamedefines.h"

/*
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "gamedefines.h"

class Player
{
    public:
        Player(int _lives);
        ~Player();

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

        void SetDirection(int _dir)
        {
            this->m_direction = _dir;
        }

        int GetDirection()
        {
            return this->m_direction;
        }

        sf::CircleShape m_object;

    private:
        int m_lives;
        bool m_isAlive;
        bool m_canMove;
        int m_direction;
};*/

class Player : public sf::Drawable, public sf::Transformable
{
    static const float acceleration;
    static const float maxSpeed;
    static const float rotationSpeed;

    public:
        Player();
        ~Player();

        void reset();
        void update(float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void onEvent(const sf::Event& event);

    private:
        sf::Vector2f speed;
        sf::ConvexShape shape;
        int h_move, v_move;
};

#endif