#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "player.h"
#include "Enemy.h"

class Game
{
    public:
        Game();
        ~Game();
        void update(float frametime);
        void onEvent(sf::Event event);
        void init(sf::RenderWindow& window);

        Player* getPlayer()
        {
            return this->player;
        }

        Enemy* getEnemy()
        {
            return this->enemy;
        }

        Player* player = new Player(); // if I use Player player() it doesn't work
        Enemy* enemy = new Enemy();
        sf::Clock clock; // for dem bullets

    //private:
        std::vector<Bullet*> m_bullets;
};

#endif