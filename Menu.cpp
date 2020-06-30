//
// Created by jarek on 23.06.2020.
//

#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {

if(!font.loadFromFile("arial.ttf"))
{
    std::cout<<"UPS.."<<std::endl;
}
die.setFont(font);
die.setFillColor(sf::Color::Red);
die.setString("YOU DIED!");
die.setPosition(sf::Vector2f((width/2)-50, 100));

win.setFont(font);
win.setFillColor(sf::Color::Blue);
win.setString("YOU WIN!");
win.setPosition(sf::Vector2f((width/2)-50, 100));

menu[0].setFont(font);
menu[0].setFillColor(sf::Color::Yellow);
menu[0].setString("PLAY");
menu[0].setPosition(sf::Vector2f((width/2-20), (height / (MAX_NUMBER_OF_ITEMS +1) *1)));

menu[1].setFont(font);
menu[1].setFillColor(sf::Color::White);
menu[1].setString("EXIT");
menu[1].setPosition(sf::Vector2f((width/2-20), (height / (MAX_NUMBER_OF_ITEMS +1) *2)));

selectedItemIndex=0;
}

Menu::~Menu() {

}

void Menu::Draw(sf::RenderWindow &window) {
for(int i=0; i<MAX_NUMBER_OF_ITEMS;i++){
    window.draw(menu[i]);
}
}

void Menu::MoveUp() {
if(selectedItemIndex -1 >=0){
    menu[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
}
}

void Menu::MoveDown() {
    if(selectedItemIndex + 1 <MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}

void Menu::Draw_die(sf::RenderWindow &window) {
    window.draw(die);
}

void Menu::Draw_win(sf::RenderWindow &window) {
    window.draw(win);
}
