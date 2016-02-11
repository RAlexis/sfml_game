#include "main.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML game");
    Renderer* renderer = new Renderer();
    Player player(3);

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

        player.Update(player.GetPlayerInput());

        std::vector<Bullet>::iterator start_bullets = player.bullets.begin();
        while (start_bullets != player.bullets.end()) {
            if (start_bullets->isAlive()) {
                start_bullets->update(1);
                ++start_bullets;
            }
            else
                start_bullets = player.bullets.erase(start_bullets);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            player.Update(SPAWN_BULLET);

        renderer->Draw(&window, &player);
    }

    return 0;
}