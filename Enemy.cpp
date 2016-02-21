#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Vector2f pos)
{
    this->healthPoints = 250;
    this->maxHP = 250;

    position = pos;

    if (!enemyTexture.loadFromFile("img/enemy_spaceship.png"))
        std::cout << "[ERROR] Could not load img/enemy_spaceship.png." << std::endl;

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
    if (healthPoints == 0) // hackfix until I do some proper stuff like a vector of enemies
        alive = false;
    
    if (position.x < -10.0f)
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -10.0f)
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;

    //enemySprite.move(0.0f, 0.5f);
    position.y += 0.5f;
    enemySprite.setPosition(position);
}