#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "gamedefines.h"

class Enemy
{
    public:
        Enemy(sf::Vector2f pos, float mSpeed);
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

        void setHP(int val)
        {
            this->healthPoints = val;
        }

        int getHP()
        {
            return this->healthPoints;
        }

        void setMaxHP(int val)
        {
            this->maxHP = val;
        }

        float getMaxHP()
        {
            return this->maxHP;
        }

        void setMoveSpeed(int val)
        {
            this->moveSpeed = val;
        }

    private:
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;
        sf::Vector2f position;
        bool alive;
        int healthPoints;
        int maxHP;
        float moveSpeed;
};

#endif
