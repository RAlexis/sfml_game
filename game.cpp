#include "game.h"

Game::Game()
{
    this->source.x = 32;
    this->source.y = 0;
}

Game::~Game()
{

}

void Game::update(float frametime)
{
    player->update();
    
    std::vector<Bullet>::iterator start_bullets = this->m_bullets.begin();
    while (start_bullets != this->m_bullets.end())
    {
        if (start_bullets->isAlive())
        {
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

    //if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space/* && this->clock.getElapsedTime().asMilliseconds() >= 175*/)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Bullet bullet(this->player->getPosition(), this->player->getDirection());
        bullet.setAlreadyFired(false);
        this->m_bullets.push_back(bullet);
        //this->clock.restart();
    }
}

void Game::init(sf::RenderWindow& window)
{
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(APP_FRAMESPERSECOND);
}