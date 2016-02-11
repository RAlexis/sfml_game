#include "menu.h"

Menu::Menu(sf::Vector2u _resolution)
{
    this->m_selectedItemIndex = 0;

    font.loadFromFile("arial.ttf");

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(_resolution.x / 2, _resolution.y / (NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Button 2");
    menu[1].setPosition(sf::Vector2f(_resolution.x / 2, _resolution.y / (NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(_resolution.x / 2, _resolution.y / (NUMBER_OF_ITEMS + 1) * 3));
}


Menu::~Menu()
{
}

void Menu::ShowMenu(sf::RenderWindow* _window)
{
    while (_window->isOpen())
    {
        sf::Event event;

        while (_window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    this->MoveUp();
                    break;

                case sf::Keyboard::Down:
                    this->MoveDown();
                    break;

                case sf::Keyboard::Space:
                case sf::Keyboard::Return:
                    switch (this->GetPressedItem())
                    {
                    case 0:
                        return;
                        break;
                    case 1:
                        std::cout << "button 2 pressed" << std::endl;
                        break;
                    case 2:
                        _window->close();
                        break;
                    }
                    break;
                }
                break;

            case sf::Event::Closed:
                _window->close();
                break;
            }
        }

        _window->clear();

        this->Draw(_window);

        _window->display();
    }
}

void Menu::MoveUp()
{
    if (this->m_selectedItemIndex - 1 >= 0)
    {
        menu[this->m_selectedItemIndex].setColor(sf::Color::White);
        --this->m_selectedItemIndex;
        menu[this->m_selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (this->m_selectedItemIndex + 1 < NUMBER_OF_ITEMS)
    {
        menu[this->m_selectedItemIndex].setColor(sf::Color::White);
        ++this->m_selectedItemIndex;
        menu[this->m_selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::Draw(sf::RenderWindow* _window)
{
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i)
    {
        _window->draw(menu[i]);
    }
}