#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
    this->lives = 1;

    position = sf::Vector2f(700, 100);

    if (!enemyTexture.loadFromFile("img/enemy_spaceship.png"))
        std::cout << "[ERROR] Could not load enemy_spaceship.png." << std::endl;

    enemySprite.setTexture(enemyTexture);
    enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    enemySprite.rotate(180.f);
    enemySprite.setPosition(position);
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    if (lives == 0)
        alive = false;

    if (position.x < -10.0f)
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -10.0f)
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;
    
    enemySprite.setPosition(position);

}