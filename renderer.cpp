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
    window.clear();

    window.draw(game.getPlayer()->getSpriteSheet());
    this->DrawBullet(window, game);

    window.display();
}

void Renderer::DrawBullet(sf::RenderWindow& window, Game& game)
{
    for (auto& i : game.m_bullets)
    {
            window.draw(i);
            //i.setAlreadyFired(true);
    }
}

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

void Renderer::DrawBullet(sf::RenderWindow* _window, Game* _game)
{
    for (std::vector<Bullet>::iterator it = _game->m_bullets.begin(); it != _game->m_bullets.end(); ++it)
        _window->draw(*it);
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