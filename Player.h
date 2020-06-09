//
// Created by jarek on 07.06.2020.
//

#ifndef PROJEKT_V2_PLAYER_H
#define PROJEKT_V2_PLAYER_H
#include <SFML\Graphics.hpp>
#include "animation.h"
#include "Collider.h"


class Player {
public:
    Player(sf::Texture* texture,sf::Vector2u imageCount, float switchTime,float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);
    void setPosition_();

    sf::Vector2f getPosition(){
       return body.getPosition();
    }

    Collider GetCollider(){
        return Collider(body);
    }

private:
    sf::RectangleShape body;
    animation Animation;
    unsigned  int row;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
};


#endif //PROJEKT_V2_PLAYER_H
