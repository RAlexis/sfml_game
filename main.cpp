#include "main.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_NAME, sf::Style::Default);
    Game game;
    game.init(window);
    Renderer renderer;

    Menu menu(window.getSize());
    menu.ShowMenu(&window);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::Escape)
                menu.ShowMenu(&window);
        }

        game.update(clock.restart().asMilliseconds());
        game.onEvent(event);
        
        renderer.Draw(window, game);
    }

    return 0;
}