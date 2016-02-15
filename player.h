#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "gamedefines.h"

class Player
{
    public:
        Player();
        ~Player();

        void setLives(int val)
        {
            this->lives = val;
        }
        
        int getLives()
        {
            return this->lives;
        }

        void setState(int state)
        {
            this->alive = state;
        }

        bool isAlive()
        {
            return this->alive;
        }

        void update();

        sf::Vector2f getPosition()
        {
            return this->position;
        }

        void setDirection(int dir)
        {
            this->direction = dir;
        }

        int getDirection()
        {
            return this->direction;
        }

        void onEvent(sf::Event& event);

        sf::Sprite getSpriteSheet()
        {
            return this->playerSprite;
        }

        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        sf::Vector2f position;

    private:
        int lives;
        bool alive;
        int direction;
};

#endif