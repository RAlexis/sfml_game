#include "player.h"
#include <iostream>
/*
Player::Player() {
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(10.0f, 0.0f));
    shape.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
    shape.setPoint(2, sf::Vector2f(-10.0f, -7.5f));

    shape.setFillColor(sf::Color(0, 0, 0, 0));
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setPosition(0.0f, 0.0f);

    reset();
}

Player::~Player()
{

}

void Player::reset() {
    setPosition(APP_WIDTH / 2, APP_HEIGHT / 2);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}

void Player::update(float frametime) {
    switch (this->getDirection())
    {
        case DIRECTION_UP:
            move(2.5, 0);
            break;

        case DIRECTION_DOWN:
            move(-2.5, 0);
            break;

        case DIRECTION_LEFT:
            move(0, -2.5);

        case DIRECTION_RIGHT:
            move(0, 2.5);
    }


    sf::Vector2f position = getPosition();

    if (position.x < -10.0f)
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -10.0f)
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;

    setPosition(position);
}

void Player::onEvent(const sf::Event& event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        std::cout << "moving up" << std::endl;
        this->setDirection(DIRECTION_UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        std::cout << "moving right" << std::endl;
        this->setDirection(DIRECTION_RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        std::cout << "moving down" << std::endl;
        this->setDirection(DIRECTION_DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "moving left" << std::endl;
        this->setDirection(DIRECTION_LEFT);
    }
}*/

Player::Player()
{
    this->setLives(3);
    position.x = APP_WIDTH / 2;
    position.y = APP_HEIGHT / 2;
    source.x = 32;
    source.y = 0;

    if (!playerTexture.loadFromFile("player.png"))
        std::cout << "[ERROR] Could not load player.png." << std::endl;

    playerSprite.setTexture(playerTexture);

    playerSprite.setPosition(position);
}

Player::~Player()
{

}

void Player::update()
{       
    time = playerClock.getElapsedTime();

    if (time.asMilliseconds() >= 300)
    {
        source.x++;

        //if (source.x * 32 >= playerTexture.getSize().x)
        if (source.x >= 3)  
            source.x = 0;

        playerClock.restart();
    }

    playerSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

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
        source.y = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //std::cout << "moving right" << std::endl;
        position.x += 2.5;
        //this->getSpriteSheet().move(0, 20);
        this->setDirection(DIRECTION_RIGHT);
        source.y = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //std::cout << "moving down" << std::endl;
        position.y += 2.5;
        //this->getSpriteSheet().move(-20, 0);
        this->setDirection(DIRECTION_DOWN);
        source.y = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //std::cout << "moving left" << std::endl;
        position.x -= 2.5;
        //this->getSpriteSheet().move(0, -20);
        this->setDirection(DIRECTION_LEFT);
        source.y = 1;
    }
}