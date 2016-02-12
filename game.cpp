#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::update(float frametime)
{
    player->update(frametime);
    
    std::vector<Bullet>::iterator start_bullets = this->m_bullets.begin();
    while (start_bullets != this->m_bullets.end()) {
        if (start_bullets->isAlive()) {
            start_bullets->update(frametime);
            ++start_bullets;
        }
        else
            start_bullets = this->m_bullets.erase(start_bullets);
    }
}

void Game::onEvent(sf::Event event)
{
    player->onEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Bullet bullet(this->player->getPosition(), this->player->getRotation());
        this->m_bullets.push_back(bullet);
    }
}