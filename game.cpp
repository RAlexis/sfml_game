#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Update()
{
    this->player->Update(this->player->GetPlayerInput());
    
    std::vector<Bullet>::iterator start_bullets = this->m_bullets.begin();
    while (start_bullets != this->m_bullets.end()) {
        if (start_bullets->isAlive()) {
            start_bullets->update(1);
            ++start_bullets;
        }
        else
            start_bullets = this->m_bullets.erase(start_bullets);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Bullet bullet(this->player->GetPosition(), this->player->m_object.getRotation(), this->player->GetDirection());
        //Bullet bullet(this->GetPosition(), this->m_object.getRotation(), this->GetDirection());
        this->m_bullets.push_back(bullet);
    }
}