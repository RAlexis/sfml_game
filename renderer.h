#ifndef _RENDERER_H
#define _RENDERER_H

#include "player.h"
#include <sstream>

class Renderer
{
    public:
        Renderer();
        ~Renderer();

        void Draw(sf::RenderWindow* _window, Player* _player);
        void DrawPlayer(sf::RenderWindow* _window, Player* _player);
        void DrawLives(sf::RenderWindow* _window, Player* _player);
        void DrawBullet(sf::RenderWindow* _window, Player* _player);
};

#endif