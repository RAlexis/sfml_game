#include "bullet.h"
#include <iostream>

const float Bullet::lifetime = 1000.0f;
const float Bullet::speed = 0.3f;

Bullet::Bullet(sf::Vector2f position)
{
    this->alive = true;
    this->remainingLife = lifetime;
    this->direction = sf::Vector2f(0, -1); // upwards

    if (!bulletTexture.loadFromFile("img/bullet.png"))
        std::cout << "[ERROR] Could not load img/bullet.png." << std::endl;

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