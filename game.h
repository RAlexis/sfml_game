#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "player.h"

class Game
{
    public:
        Game();
        ~Game();
        void update(float frametime);
        void onEvent(sf::Event event);

        Player* getPlayer()
        {
            return this->player;
        }

        Player* player = new Player(); // if I use Player player() it doesn't work

    //private:
        std::vector<Bullet> m_bullets; // return m_bullets using a function and make this private
};

#endif