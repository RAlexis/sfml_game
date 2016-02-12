#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define NUMBER_OF_ITEMS 3 // number of buttons in the menu

class Menu
{
    public:
        Menu(sf::Vector2u _resolution);
        ~Menu();

        void ShowMenu(sf::RenderWindow* _window);

        void MoveUp();

        void MoveDown();

        int GetPressedItem()
        {
            return m_selectedItemIndex;
        }

        void Draw(sf::RenderWindow* window);

    private:
        int m_selectedItemIndex;
        sf::Font font;
        sf::Text menu[NUMBER_OF_ITEMS];
};

#endif