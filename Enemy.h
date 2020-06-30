//
// Created by jarek on 18.06.2020.
//

#ifndef PROJEKT_V2_ENEMY_H
#define PROJEKT_V2_ENEMY_H
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "animation.h"



class Enemy {
public:
    Enemy(sf::Texture* texture,sf::Vector2u imageCount, float switchTime,sf::Vector2f position);
    ~Enemy();

    void Draw(sf::RenderWindow& window);
    Collider GetCollider(){
        return Collider(body);}
    sf::Vector2f GetPosition()
    {return body.getPosition();}
    void Move(float dx, float dy){
        body.move(dx,dy);
    }
    void Row(int a){
        a=row;
    }
void Update(float deltaTime){
    deltaTime=deltaTime;
    }

    sf::IntRect  uvRect;

    private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float deltaTime;
    float totalTime;
    float switchTime;
    unsigned  int row;
    sf::RectangleShape body;



};


#endif //PROJEKT_V2_ENEMY_H
