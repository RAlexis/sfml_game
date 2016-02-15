#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Graphics.hpp>
#include "gamedefines.h"

/*
class Bullet
{
    static const float lifetime;
    static const float speed;

public:
    Bullet(sf::Vector2f position);
    ~Bullet();

    bool isAlive();
    void kill();
    void update(float frametime);

    void setAlreadyFired(bool val)
    {
        this->alreadyFired = val;
    }

    bool hasAlreadyFired()
    {
        return alreadyFired;
    }

    sf::Sprite getSprite()
    {
        return this->bulletSprite;
    }

    sf::Texture bulletTexture;
    sf::Sprite bulletSprite;

private:
    bool is_alive;
    float remaining_life;
    sf::Vector2f direction;
    bool alreadyFired;
};
*/

class Bullet
{
    static const float lifetime;
    static const float speed;

    public:
        Bullet(sf::Vector2f position);
        ~Bullet();
        void update(float frametime);

        bool isAlive()
        {
            return this->alive;
        }

        void kill()
        {
            this->alive = false;
        }

        sf::Sprite getSprite()
        {
            return this->bulletSprite;
        }

        sf::Texture bulletTexture;
        sf::Sprite bulletSprite;
        
    private:
        bool alive;
        float remainingLife;
        sf::Vector2f direction;
};
#endif