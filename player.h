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

        void setLives(int lives)
        {
            this->m_lives = lives;
        }
        
        int getLives()
        {
            return this->m_lives;
        }

        bool setState(bool _state)
        {
            this->m_isAlive = _state;
        }

        bool isAlive()
        {
            return this->m_isAlive;
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

        sf::Clock playerClock;
        sf::Time time;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        sf::Vector2f position;
        sf::Vector2i source;

    private:
        int m_lives;
        bool m_isAlive;
        int direction;
};

#endif