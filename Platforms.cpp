//
// Created by jarek on 07.06.2020.
//

#include "Platforms.h"

Platforms::Platforms(sf::Texture *texture,sf::Vector2f size, sf::Vector2f position) {
body.setSize(size);
body.setOrigin(size/2.0f);
body.setTexture(texture);
body.setPosition(position);
}

Platforms::~Platforms() {

}

void Platforms::Draw(sf::RenderWindow &window) {
window.draw(body);
}
