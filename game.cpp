#include "game.h"
#include <iostream>

Game::Game()
{

}

Game::~Game()
{

}

void Game::update(float frametime)
{
    player->update();
    enemy->update();
    
    std::vector<Bullet*>::iterator start_bullets = this->m_bullets.begin();
    while (start_bullets != this->m_bullets.end())
    {
        if ((*start_bullets)->isAlive())
        {
            (*start_bullets)->update(frametime);

            sf::FloatRect b = (*start_bullets)->getSprite().getGlobalBounds();
            sf::FloatRect e = enemy->getSpriteSheet().getGlobalBounds();
            
            if (b.intersects(e))
                enemy->setState(STATE_DEAD);
                //enemy->setPosition(sf::Vector2f(enemy->getPosition().x + 2.5f, enemy->getPosition().y));

            ++start_bullets;
        }
        else
            start_bullets = this->m_bullets.erase(start_bullets);
    }

    // COLLISION
    sf::FloatRect p = player->getSpriteSheet().getGlobalBounds();
    sf::FloatRect e = enemy->getSpriteSheet().getGlobalBounds();

    if (p.intersects(e))
        //enemy->setState(STATE_DEAD);
        enemy->setPosition(sf::Vector2f(enemy->getPosition().x + 2.5f, enemy->getPosition().y));
}

void Game::onEvent(sf::Event event)
{
    player->onEvent(event);

    //if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space/* && this->clock.getElapsedTime().asMilliseconds() >= 175*/)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //Bullet bullet(this->player->getPosition());
        //this->m_bullets.push_back(&bullet);
        this->m_bullets.push_back(new Bullet(this->player->getPosition()));
        //this->clock.restart();
    }
}

void Game::init(sf::RenderWindow& window)
{
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(APP_FRAMESPERSECOND);
    window.setVerticalSyncEnabled(true);
}