#include "renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

// Main draw function
void Renderer::Draw(sf::RenderWindow* _window, Player* _player, Game* _game)
{
    _window->clear();

    this->DrawPlayer(_window, _player);
    this->DrawLives(_window, _player);
    this->DrawBullet(_window, _game);

    _window->display();
}

void Renderer::DrawPlayer(sf::RenderWindow* _window, Player* _player)
{
    _window->draw(_player->m_object);
}

void Renderer::DrawLives(sf::RenderWindow* _window, Player* _player)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    std::ostringstream tmp;
    tmp << "Lives: " << _player->GetLives();

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