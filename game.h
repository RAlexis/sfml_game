#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bullet.h"
#include "player.h"
#include "Enemy.h"
#include "Collision.h"

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

        int getKillCounter()
        {
            return this->killCounter;
        }

        Player* player = new Player();
        float remainingLife;
        sf::SoundBuffer buffer;
        sf::Sound sound;

    //private:
        std::vector<Bullet*> m_bullets;
        std::vector<Enemy*> enemies;
        int killCounter;
        int newEnemyBaseHP;
};

#endif