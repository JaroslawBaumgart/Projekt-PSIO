//
// Created by jarek on 03.06.2020.
//

#ifndef PROJEKT_V2_ANIMATION_H
#define PROJEKT_V2_ANIMATION_H
#include <SFML\Graphics.hpp>


class animation {
public:
    animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);
    ~animation();

    void Update(int row, float deltaTime, bool faceRight);


    sf::IntRect  uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};


#endif //PROJEKT_V2_ANIMATION_H
