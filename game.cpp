#include "game.h"
#include <iostream>

Game::Game()
{
    /*if (buffer.loadFromFile("audio/Laser_Shoot.wav"))
    {
        sound.setBuffer(buffer);
        sound.setPitch(1.5);
        sound.setVolume(7.5);
        //sound.play();
    }
    else
        std::cout << "[ERROR] Could not load audio/Laser_Shoot.wav." << std::endl;*/
}

Game::~Game()
{

}

void Game::update(float frametime)
{
    player->update();

    for (auto& enemy : enemies)
        enemy->update();
    
    std::vector<Bullet*>::iterator start_bullets = this->m_bullets.begin();
    while (start_bullets != this->m_bullets.end())
    {
        if ((*start_bullets)->isAlive())
        {
            (*start_bullets)->update(frametime);
            remainingLife = (*start_bullets)->getRemainingLife();

            //if (Collision::PixelPerfectTest((*start_bullets)->getSprite(), enemy->getSpriteSheet(), 0))
                //enemy->setState(STATE_DEAD);
           // {
                //enemy->setLives(enemy->getLives() - 1);
               // enemy->setState(STATE_DEAD);
                //enemy->setPosition(sf::Vector2f(-500, -500));
                //std::cout << "enemy has " << enemy->getLives() << " lives left." << std::endl;
          //  }

            for (auto& enemy : enemies)
            {
                if (Collision::PixelPerfectTest((*start_bullets)->getSprite(), enemy->getSpriteSheet(), 0))
                    enemy->setLives(enemy->getLives() - 1);

                if (enemy->getLives() < 0)
                    enemy->setState(STATE_DEAD);
            }

            ++start_bullets;
        }
        else
            start_bullets = this->m_bullets.erase(start_bullets);
    }

    for (auto& enemy : enemies)
    {
        //this->m_bullets.push_back(new Bullet(enemy->getPosition()));

        if (Collision::PixelPerfectTest(player->getSpriteSheet(), enemy->getSpriteSheet(), 0))
        {
            enemy->setState(STATE_DEAD);
            player->onCollision();
        }
    }

   // if (Collision::PixelPerfectTest(player->getSpriteSheet(), enemy->getSpriteSheet(), 0))
     //   enemy->setPosition(sf::Vector2f(enemy->getPosition().x + 2.5f, enemy->getPosition().y));
}

void Game::onEvent(sf::Event event)
{
    player->onEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) /*&& m_bullets.size() < 1*/)
    //if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space && remainingLife <= 750.f)
    {
        this->m_bullets.push_back(new Bullet(this->player->getPosition()));
        //sound.play();
    }
}

void Game::init(sf::RenderWindow& window)
{
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(APP_FRAMESPERSECOND);
    window.setVerticalSyncEnabled(true);
}