#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "gamedefines.h"

class Enemy
{
    public:
        Enemy(sf::Vector2f pos);
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
            return this->enemySprite.getPosition();
        }

        void setState(int state)
        {
            this->alive = state;

            if (state == STATE_DEAD)
                this->healthPoints = 0;
        }

        bool isAlive()
        {
            return this->alive;
        }

        int getLives()
        {
            return this->healthPoints;
        }

        void setLives(int val)
        {
            this->healthPoints = val;
        }

        float getMaxHP()
        {
            return this->maxHP;
        }

        int getHealth()
        {
            return this->healthPoints;
        }

    private:
        int healthPoints;
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;
        sf::Vector2f position;
        bool alive;
        float maxHP;
};

#endif
