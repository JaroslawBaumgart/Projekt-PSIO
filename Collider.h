//
// Created by jarek on 07.06.2020.
//

#ifndef PROJEKT_V2_COLLIDER_H
#define PROJEKT_V2_COLLIDER_H
#include <SFML/Graphics.hpp>
#include <iostream>



class Collider {
public:
    Collider(sf::RectangleShape& body);
    ~Collider();


    void Move(float dx, float dy){
        body.move(dx,dy);
    }



    bool CheckCollision(Collider other, sf::Vector2f & direction, float pushX, float pushY);
    sf::Vector2f GetPosition(){return body.getPosition();}
    sf::Vector2f GetHalfSize(){return body.getSize() / 2.0f;}



private:
    sf::RectangleShape& body;

};


#endif //PROJEKT_V2_COLLIDER_H
