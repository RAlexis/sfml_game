#include "main.h"

int main()
{
    Game game;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML game");
    Renderer renderer;

    Menu menu(window.getSize());
    menu.ShowMenu(&window);

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

        game.Update();
        renderer.Draw(&window, game.getPlayer(), &game);
    }

    return 0;
}