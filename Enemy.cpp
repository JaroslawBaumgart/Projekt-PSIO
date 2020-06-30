//
// Created by jarek on 18.06.2020.
//

#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture,sf::Vector2u imageCount, float switchTime,sf::Vector2f position)

{



    body.setSize(sf::Vector2f(35.0f,55.0f));
    body.setOrigin((body.getSize()/2.0f));
    body.setPosition(position);
    body.setTexture(texture);
   // this->imageCount = imageCount;
   // this->switchTime = switchTime;
   // this->totalTime=0.0f;
   // currentImage.x=0;
//
   // uvRect.width = texture->getSize().x / float(imageCount.x);
   // uvRect.height = texture->getSize().y / float(imageCount.y);
//
   // currentImage.y =row;
   // totalTime += deltaTime;
   // if(totalTime >= switchTime)
   // {
   //     totalTime-=switchTime;
   //     currentImage.x++;
   //    if(currentImage.x >= imageCount.x)
   //    {
   //        currentImage.x=0;
   //    }
   //}

   //uvRect.top = currentImage.y* uvRect.height;

   //uvRect.left = currentImage.x * uvRect.width;
   //uvRect.width = abs(uvRect.width);


   //body.setTextureRect(uvRect);
}

Enemy::~Enemy() {

}


void Enemy::Draw(sf::RenderWindow &window) {
    window.draw(body);
}


