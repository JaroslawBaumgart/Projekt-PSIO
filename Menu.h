//
// Created by jarek on 23.06.2020.
//

#ifndef PROJEKT_V2_MENU_H
#define PROJEKT_V2_MENU_H
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 2


class Menu {
public:
    Menu(float width,float height);
    ~Menu();
    void Draw(sf::RenderWindow& window);
    void Draw_die(sf::RenderWindow& window);
    void Draw_win(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem()
    { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text die;
    sf::Text win;
};


#endif //PROJEKT_V2_MENU_H
