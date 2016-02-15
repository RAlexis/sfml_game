#include "bullet.h"
#include <iostream>
/*

const float Bullet::lifetime = 1000.0f;
const float Bullet::speed = 0.3f;

Bullet::Bullet(sf::Vector2f position)
{
    this->is_alive = true;
    this->remaining_life = lifetime;
    this->direction = sf::Vector2f(0, -1); // upwards

    if (bulletTexture.loadFromFile("bullet.png"))
        bulletSprite.setTexture(bulletTexture);
    else
        std::cout << "[ERROR] Could not load bullet.png." << std::endl;

    bulletSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    //bulletSprite.setTexture(bulletTexture);
    bulletSprite.setPosition(position.x + 16, position.y);
    //this->setPosition(sf::Vector2f(position.x + 16, position.y));

}

Bullet::~Bullet()
{

}

bool Bullet::isAlive()
{
    return is_alive;
}

void Bullet::update(float frametime)
{
    if (!is_alive)
        return;

    remaining_life -= frametime;

    if (remaining_life <= 0)
        is_alive = false;
    
    sf::Vector2f distance = direction * speed * frametime;
    bulletSprite.move(distance);
}

void Bullet::kill()
{
    is_alive = false;
}
*/

const float Bullet::lifetime = 1000.0f;
const float Bullet::speed = 0.3f;

Bullet::Bullet(sf::Vector2f position)
{
    this->alive = true;
    this->remainingLife = lifetime;
    this->direction = sf::Vector2f(0, -1); // upwards

    if (!bulletTexture.loadFromFile("img/bullet.png"))
        std::cout << "[ERROR] Could not load bullet.png." << std::endl;

    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    bulletSprite.setPosition(position.x, position.y - 16);
}

Bullet::~Bullet()
{

}

void Bullet::update(float frametime)
{
    if (!alive)
        return;

    remainingLife -= frametime;

    if (remainingLife <= 0)
        alive = false;

    sf::Vector2f distance = direction * speed * frametime;
    bulletSprite.move(distance);
}