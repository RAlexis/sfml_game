#include "player.h"
#include <iostream>

Player::Player()
{
    this->lives = 3;
    position.x = APP_WIDTH / 2;
    position.y = APP_HEIGHT / 2;

    if (!playerTexture.loadFromFile("img/player_spaceship.png"))
        std::cout << "[ERROR] Could not load player_spaceship.png." << std::endl;

    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    playerSprite.setPosition(position);
}

Player::~Player()
{

}

void Player::update()
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

    playerSprite.setPosition(position);
}

void Player::onEvent(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //std::cout << "moving up" << std::endl;
        position.y -= 2.5;
        //this->getSpriteSheet().move(0, 2.5);
        this->setDirection(DIRECTION_UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //std::cout << "moving right" << std::endl;
        position.x += 2.5;
        //this->getSpriteSheet().move(0, 20);
        this->setDirection(DIRECTION_RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //std::cout << "moving down" << std::endl;
        position.y += 2.5;
        //this->getSpriteSheet().move(-20, 0);
        this->setDirection(DIRECTION_DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //std::cout << "moving left" << std::endl;
        position.x -= 2.5;
        //this->getSpriteSheet().move(0, -20);
        this->setDirection(DIRECTION_LEFT);
    }
}