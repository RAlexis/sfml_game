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
        void Update();

        Player* getPlayer()
        {
            return this->player;
        }

    //private:
        //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML game");
        //Menu menu(window.getSize());
        //Renderer* renderer = new Renderer();
        Player* player = new Player(3); // if I use Player player(3) it doesn't work

    //private:
        std::vector<Bullet> m_bullets;

};

#endif