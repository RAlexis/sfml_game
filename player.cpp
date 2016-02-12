#include "player.h"
#include <iostream> // print to console

Player::Player(int _lives)
{
    this->m_lives = _lives;
    this->m_canMove = true;

    this->m_object.setRadius(5);
    this->m_object.setPosition(200, 200);
    this->m_object.setFillColor(sf::Color::Red);

}

Player::~Player()
{

}

///!!! TODO: switch()
int Player::GetPlayerInput()
{
  //  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    //    return SPAWN_BULLET;

    // MOVEMENT INPUT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            return MOVE_UP_LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            return MOVE_UP_RIGHT;
        else
            return MOVE_UP;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            return MOVE_DOWN_LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            return MOVE_DOWN_RIGHT;
        else
            return MOVE_DOWN;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return MOVE_LEFT;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return MOVE_RIGHT;

    // END MOVEMENT INPUT

    return INPUT_NULL;
}

void Player::Update(int _moveInput)
{
    if (this->CanMove()) // safe to remove
    {
        switch (_moveInput)
        {
            case INPUT_NULL:
                return;
                break;

            case MOVE_UP:
                if (this->CanMoveToPoint(0, PLAYER_SPEED_UP))
                    this->m_object.move(0, PLAYER_SPEED_UP);
                break;

            case MOVE_DOWN:
                if (this->CanMoveToPoint(0, PLAYER_SPEED_DOWN))
                    this->m_object.move(0, PLAYER_SPEED_DOWN);
                break;

            case MOVE_LEFT:
                this->SetDirection(MOVE_LEFT);
                if (this->CanMoveToPoint(PLAYER_SPEED_LEFT, 0))
                    this->m_object.move(PLAYER_SPEED_LEFT, 0);
                break;

            case MOVE_RIGHT:
                this->SetDirection(MOVE_RIGHT);
                if (this->CanMoveToPoint(PLAYER_SPEED_RIGHT, 0))
                    this->m_object.move(PLAYER_SPEED_RIGHT, 0);
                break;

            case MOVE_UP_LEFT:
                if (this->CanMoveToPoint(PLAYER_SPEED_LEFT, PLAYER_SPEED_UP))
                    this->m_object.move(PLAYER_SPEED_LEFT / std::sqrt(2.f), PLAYER_SPEED_UP / std::sqrt(2.f));
                break;

            case MOVE_UP_RIGHT:
                if (this->CanMoveToPoint(PLAYER_SPEED_RIGHT, PLAYER_SPEED_UP))
                    this->m_object.move(PLAYER_SPEED_RIGHT / std::sqrt(2.f), PLAYER_SPEED_UP / std::sqrt(2.f));
                break;

            case MOVE_DOWN_LEFT:
                if (this->CanMoveToPoint(PLAYER_SPEED_LEFT, PLAYER_SPEED_DOWN))
                    this->m_object.move(PLAYER_SPEED_LEFT / std::sqrt(2.f), PLAYER_SPEED_DOWN / std::sqrt(2.f));
                break;

            case MOVE_DOWN_RIGHT:
                if (this->CanMoveToPoint(PLAYER_SPEED_RIGHT, PLAYER_SPEED_DOWN))
                    this->m_object.move(PLAYER_SPEED_RIGHT / std::sqrt(2.f), PLAYER_SPEED_DOWN / std::sqrt(2.f));
                break;

            // I think it's safe to remove, but I'll keep the code for some time until I'm sure
            //case SPAWN_BULLET:
                //std::cout << "spawn bullet" << std::endl;
                //Bullet bullet(this->GetPosition(), this->m_object.getRotation(), this->GetDirection());
                //this->bullets.push_back(bullet);
                //break;
        }
    }
}

bool Player::CanMoveToPoint(float _xVal, float _yVal) // movement collision with the boundaries of the map
{
    int y = this->GetPosition().y;
    int x = this->GetPosition().x;

    if (y + _yVal > HEIGHT - this->GetRadius())
        return false;

    if (y + _yVal < 0)
        return false;

    if (x + _xVal > WIDTH - this->GetRadius())
        return false;

    if (x + _xVal < 0)
        return false;

    return true;
}