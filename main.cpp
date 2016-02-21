#include "main.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    sf::RenderWindow window(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_NAME, sf::Style::Default);
    Game game;
    game.init(window);
    Renderer renderer;

    Menu menu(window.getSize());
    menu.ShowMenu(&window);

    //game.enemies.push_back(new Enemy());
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        float randX = rand() % 800 + 1;
        //float randY = rand() % 600 + 1;
        float randY = -(rand() % 100 + 1);
        std::cout << randX << " " << randY << " ";
        game.enemies.push_back(new Enemy(sf::Vector2f(randX, randY)));
    }

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