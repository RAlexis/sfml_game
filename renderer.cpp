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

    for (auto& enemy : game.enemies)
    {
        if (enemy->isAlive())
        {
            window.draw(enemy->getSpriteSheet());
            DrawHealthBar(window, *enemy);
        }
    }

    for (auto& bullet : game.m_bullets)
        window.draw(bullet->getSprite());

    drawLives(window, *game.getPlayer());
    drawKillCounter(window, game);

    window.display();
}


void Renderer::drawLives(sf::RenderWindow& window, Player& player)
{
    sf::Texture heartTexture;
    sf::Sprite heartSprite;

    if (!heartTexture.loadFromFile("img/heart.png"))
        std::cout << "[ERROR] Could not load heart.png." << std::endl;

    heartSprite.setTexture(heartTexture);
    heartSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    heartSprite.setScale(0.6f, 0.6f);
    heartSprite.setPosition(0, 575);


    sf::Font font;
    font.loadFromFile("arial.ttf");

    std::ostringstream tmp;
    tmp << "x" << player.getHP();

    sf::Text text(tmp.str(), font);
    text.setCharacterSize(15);
    text.setColor(sf::Color::Green);
    text.setPosition(20, 575);

    window.draw(heartSprite);
    
    window.draw(text);
}

void Renderer::DrawHealthBar(sf::RenderWindow& window, Enemy& enemy)
{
    sf::RectangleShape healthBar(sf::Vector2f(32, 5));
    healthBar.setFillColor(sf::Color::Red);
    healthBar.setScale(static_cast<float>(enemy.getHP()) / enemy.getMaxHP(), 1);
    healthBar.setPosition(enemy.getPosition().x - 32, enemy.getPosition().y - 45);

    window.draw(healthBar);
}

void Renderer::drawKillCounter(sf::RenderWindow& window, Game& game)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    std::ostringstream tmp;
    tmp << "Kills: " << game.getKillCounter();

    sf::Text text(tmp.str(), font);
    text.setCharacterSize(15);
    text.setColor(sf::Color::Red);
    text.setPosition(0, 0);

    window.draw(text);
}

/*
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