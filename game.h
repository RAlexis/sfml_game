#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
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

        Player* player = new Player(); // if I use Player player() it doesn't work
        //Enemy* enemy = new Enemy();
        float remainingLife;
        //sf::SoundBuffer buffer;
        //sf::Sound sound;

    //private:
        std::vector<Bullet*> m_bullets;
        std::vector<Enemy*> enemies;
};

#endif