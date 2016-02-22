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
        void drawLives(sf::RenderWindow& window, Player& player);
        void DrawHealthBar(sf::RenderWindow& window, Enemy& enemy);
        void drawKillCounter(sf::RenderWindow& window, Game& game);

    private:
        sf::Texture bgTexture;
        sf::Sprite bgSprite;
};

#endif