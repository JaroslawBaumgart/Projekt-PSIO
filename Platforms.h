//
// Created by jarek on 07.06.2020.
//

#ifndef PROJEKT_V2_PLATFORMS_H
#define PROJEKT_V2_PLATFORMS_H
#include <SFML/Graphics.hpp>
#include "Collider.h"


class Platforms {

public:
Platforms(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
~Platforms();

void Draw(sf::RenderWindow& window);
Collider GetCollider(){
    return Collider(body);
}

private:
    sf::RectangleShape body;


};


#endif //PROJEKT_V2_PLATFORMS_H
