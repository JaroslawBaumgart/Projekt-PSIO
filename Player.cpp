//
// Created by jarek on 07.06.2020.
//

#include "Player.h"
#include <math.h>


Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
Animation(texture, imageCount, switchTime)
{
this->speed=speed;
this->jumpHeight=jumpHeight;

row=0;
faceRight=true;

    body.setSize(sf::Vector2f(50.0f,75.0f));
    body.setOrigin((body.getSize()/2.0f));
    body.setPosition(400.0f,300.0f);
    body.setTexture(texture);
}

Player::~Player() {

}

void Player::Update(float deltaTime) {

    velocity.x *= 0.0f;

if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    velocity.x -= speed;
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    velocity.x += speed;
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& canJump){
    canJump=false;
    velocity.y=-sqrtf((2.0f * 981.0f * jumpHeight)/2);

}

velocity.y +=981.0f * deltaTime;


if(velocity.x == 0.0f){
    row=1;
}
else{
    row=0;

    if(velocity.x > 0.0f){
        faceRight = true;
    }
    else{
        faceRight= false;
    }
}
if(!canJump) {
    row = 2;
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)||sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    row=3;
}


Animation.Update(row, deltaTime, faceRight);
body.setTextureRect(Animation.uvRect);
body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction) {
if(direction.x < 0.0f){
    velocity.x = 0.0f;
}
else if(direction.x> 0.0f){
    velocity.x = 0.0f;
}
if (direction.y < 0.0f){
    velocity.y = 0.0f;
    canJump = true;
}
else if(direction.y > 0.0f){
    velocity.y = 0.0f;
}
}
void Player::setPosition_(){
    body.setPosition(400.0f,300.0f);
}

