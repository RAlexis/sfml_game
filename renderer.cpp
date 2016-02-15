#include "renderer.h"
#include <iostream>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

// Main draw function
void Renderer::Draw(sf::RenderWindow& window, Game& game)
{
    window.clear(sf::Color(25, 25, 112));

    if (game.getPlayer()->isAlive())
        window.draw(game.getPlayer()->getSpriteSheet());

    if (game.getEnemy()->isAlive())
        window.draw(game.getEnemy()->getSpriteSheet());

    for (auto& bullet : game.m_bullets)
        window.draw(bullet->getSprite());

    window.display();
}

// might make use of them
/*

void Renderer::DrawLives(sf::RenderWindow* _window, Player* _player)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    std::ostringstream tmp;
   // tmp << "Lives: " << _player->GetLives();

    sf::Text text(tmp.str(), font);
    text.setCharacterSize(15);
    text.setColor(sf::Color::Green);
    text.setPosition(0, 575);

    _window->draw(text);
}

void Renderer::DrawText(sf::RenderWindow* _window, Game* _game)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    std::ostringstream tmp;
    tmp << "Bullets: " << _game->m_bullets.size();

    sf::Text text(tmp.str(), font);
    text.setCharacterSize(15);
    text.setColor(sf::Color::Green);
    text.setPosition(0, 555);

    _window->draw(text);
}
*/