#ifndef _RENDERER_H
#define _RENDERER_H

#include "player.h"
#include "game.h"
#include <sstream>

class Renderer
{
    public:
        Renderer();
        ~Renderer();

        void Draw(sf::RenderWindow& window, Game& game);
        //void DrawLives(sf::RenderWindow* _window, Player* _player);
        void DrawBullet(sf::RenderWindow& window, Game& game);
        //void DrawText(sf::RenderWindow * _window, Game * _game);
};

#endif