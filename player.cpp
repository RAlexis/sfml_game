#include "player.h"
#include <iostream>

Player::Player()
{
    this->healthPoints = 3;
    position.x = APP_WIDTH / 2;
    position.y = APP_HEIGHT / 2;

    if (!playerTexture.loadFromFile("img/player_spaceship.png"))
        std::cout << "[ERROR] Could not load img/player_spaceship.png." << std::endl;

    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    playerSprite.setPosition(position);
}

Player::~Player()
{

}

void Player::update()
{
    if (healthPoints == 0)
        alive = false;

    if (position.x < -10.0f)
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -10.0f)
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;

    playerSprite.setPosition(position);
}

void Player::onEvent(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.y -= 2.5;
        this->setDirection(DIRECTION_UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += 2.5;
        this->setDirection(DIRECTION_RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.y += 2.5;
        this->setDirection(DIRECTION_DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position.x -= 2.5;
        this->setDirection(DIRECTION_LEFT);
    }
}

void Player::onCollision()
{
    this->setPosition(sf::Vector2f(300, 300));
    this->setHP(healthPoints - 1);
}
