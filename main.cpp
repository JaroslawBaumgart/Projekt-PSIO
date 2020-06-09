#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Player.h"
#include "Platforms.h"
#include <vector>

static const float View_Height=512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(View_Height * aspectRatio, View_Height);
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(800,600),"Platformer", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f (0.0f, 0.0f),sf::Vector2f(View_Height,View_Height));
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("test6.png"))
    { std::cout<<"UPS.."<<std::endl; }

    Player player(&playerTexture, sf::Vector2u(8,4),0.3f,100.0f, 200.0f);



    sf::Texture floor;
    if(!floor.loadFromFile("wall.png"))
    { std::cout<<"UPS.."<<std::endl; }
    floor.setRepeated(true);

    sf::Texture water;
    if(!water.loadFromFile("woda_test.png"))
    { std::cout<<"UPS.."<<std::endl; }
    water.setRepeated(true);

    sf::Texture wood;
    if(!wood.loadFromFile("wood_test.png"))
    { std::cout<<"UPS.."<<std::endl; }
    wood.setRepeated(true);

    std::vector<Platforms> platforms;
    std::vector<Platforms> dyn_platforms;
    std::vector<Platforms> kill;
    std::vector<Platforms> push_wall;

    dyn_platforms.push_back(Platforms(&floor, sf::Vector2f(400.0f,200.0f),sf::Vector2f(0.0f, 500.f)));
    dyn_platforms.push_back(Platforms(&floor, sf::Vector2f(400.0f,200.0f),sf::Vector2f(-450.0f, 500.f)));
    platforms.push_back(Platforms(&floor, sf::Vector2f(350.0f,200.0f),sf::Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platforms(&floor, sf::Vector2f(400.0f,200.0f),sf::Vector2f(500.0f, 500.f)));
    kill.push_back(Platforms(&water, sf::Vector2f(3000.0f,300.0f),sf::Vector2f(500.0f, 700.0f)));
    push_wall.push_back(Platforms(&wood, sf::Vector2f(25.0f,38.0f),sf::Vector2f(500.0f, 350.0f)));

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f / 30.0f){
            deltaTime = 1.0 / 30.0f;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    ResizeView(window, view);
                    break;

            }
        }


        player.Update(deltaTime);

        sf::Vector2f direction;

        for (Platforms &platform : platforms) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f,1.0f)) {
                player.OnCollision(direction);
            }
        }

        for (Platforms &platform : dyn_platforms) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f,0.0f)) {
                player.OnCollision(direction);
            }
        }

        for (Platforms &platform : kill) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f,1.0f)) {
                player.OnCollision(direction);
                player.setPosition_();
            }
        }

        for (Platforms &platform : push_wall) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f,1.0f)) {
                player.OnCollision(direction);
            }
        }


        view.setCenter(player.getPosition());

        window.setView(view);
        window.clear(sf::Color::Black);
        player.Draw(window);
        for(Platforms& platforms : platforms){
            platforms.Draw(window);
        }

        for(Platforms& platforms : dyn_platforms){
            platforms.Draw(window);
        }
        for(Platforms& platforms : kill){
            platforms.Draw(window);
        }

        for(Platforms& platforms : push_wall){
            platforms.Draw(window);
        }

        window.display();
    }

    return 0;
}