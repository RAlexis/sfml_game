#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "gamedefines.h"

class Enemy
{
    public:
        Enemy();
        ~Enemy();
        void update();

        sf::Sprite getSpriteSheet()
        {
            return this->enemySprite;
        }

        void setPosition(sf::Vector2f pos)
        {
            this->position = pos;
        }

        sf::Vector2f getPosition()
        {
            return this->position;
        }

        void setState(int state)
        {
            this->alive = state;
        }

        bool isAlive()
        {
            return this->alive;
        }

    private:
        int lives;
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;
        sf::Vector2f position;
        bool alive;
};

#endif
