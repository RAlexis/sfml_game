#include "game.h"
#include <iostream>

Game::Game()
{
    if (buffer.loadFromFile("audio/Laser_Shoot.wav"))
    {
        sound.setBuffer(buffer);
        sound.setPitch(1.5);
        sound.setVolume(7.5);
    }
    else
        std::cout << "[ERROR] Could not load audio/Laser_Shoot.wav." << std::endl;

    this->killCounter = 0;
    this->newEnemyBaseHP = 25;
}

Game::~Game()
{

}

void Game::update(float frametime)
{
    player->update();
    
    std::vector<Bullet*>::iterator start_bullets = this->m_bullets.begin();
    while (start_bullets != this->m_bullets.end())
    {
        if ((*start_bullets)->isAlive())
        {
            (*start_bullets)->update(frametime);
            remainingLife = (*start_bullets)->getRemainingLife();

            for (auto& enemy : enemies)
            {
                if (Collision::PixelPerfectTest((*start_bullets)->getSprite(), enemy->getSpriteSheet(), 0))
                {
                    enemy->setHP(enemy->getHP() - 1);
                    (*start_bullets)->kill();
                }

                if (enemy->getHP() < 0)
                    enemy->setState(STATE_DEAD);
            }

            ++start_bullets;
        }
        else
            start_bullets = this->m_bullets.erase(start_bullets);
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->update();

        if (!enemies[i]->isAlive())
        {
            ++killCounter;

            if (killCounter % 5 == 0)
            {
                player->setHP(player->getHP() + 1);

                float randX = rand() % 800 + 1;
                float randY = (rand() % 100 + 1);
                float moveSpeed = rand() % 2 + 0.5;

                Enemy* enemy = new Enemy(sf::Vector2f(randX, randY), moveSpeed);
                enemy->setMaxHP(newEnemyBaseHP);
                enemy->setHP(newEnemyBaseHP);

                enemies.push_back(enemy);
            }

            float randX = rand() % 800 + 1;
            float randY = (rand() % 100 + 1);
            float moveSpeed = rand() % 2 + 0.5;

            Enemy* enemy = new Enemy(sf::Vector2f(randX, randY), moveSpeed);
            newEnemyBaseHP = newEnemyBaseHP + 1;
            enemy->setMaxHP(newEnemyBaseHP);
            enemy->setHP(newEnemyBaseHP);

            enemies[i] = enemy;
            continue;
        }

        if (Collision::PixelPerfectTest(player->getSpriteSheet(), enemies[i]->getSpriteSheet(), 0))
        {
            enemies[i]->setState(STATE_DEAD);
            player->onCollision();
            ++killCounter;
        }
    }
}

void Game::onEvent(sf::Event event)
{
    player->onEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
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

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        float randX = rand() % 800 + 100;
        float randY = (rand() % 100 + 1);
        float moveSpeed = rand() % 2 + 0.5;

        enemies.push_back(new Enemy(sf::Vector2f(randX, randY), moveSpeed));
    }
}