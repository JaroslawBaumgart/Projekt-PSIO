#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Player.h"
#include "Platforms.h"
#include "Enemy.h"
#include "Menu.h"
#include <vector>

static const float View_Height=512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(View_Height * aspectRatio, View_Height);
}


std::vector<Platforms> platforms_(sf::Texture& floor){
    std::vector<Platforms> platforms_;
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,200.0f),sf::Vector2f(150.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,200.0f),sf::Vector2f(550.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,250.0f),sf::Vector2f(950.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,200.0f),sf::Vector2f(1650.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,200.0f),sf::Vector2f(2100.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(2350.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(3000.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(3400.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(3800.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(4600.0f, 700.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(4950.0f, 650.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(5300.0f, 600.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(5650.0f, 550.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(6000.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(8450.0f, 550.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(8850.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(9250.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(9550.0f, 500.0f)));
    platforms_.push_back(Platforms(&floor, sf::Vector2f(300.0f,350.0f),sf::Vector2f(10400.0f, 500.0f)));




    return platforms_;
}

std::vector<Platforms> dyn_platforms_(sf::Texture& dyn_floor){
    std::vector<Platforms> dyn_platforms_;
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(200.0f,20.0f),sf::Vector2f(1300.0f, 400.f)));
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(200.0f,20.0f),sf::Vector2f(2700.0f, 300.f)));
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(200.0f,20.0f),sf::Vector2f(4250.0f, 500.f)));
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(600.0f,20.0f),sf::Vector2f(6550.0f, 300.f)));
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(600.0f,20.0f),sf::Vector2f(7200.0f, 300.f)));
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(600.0f,20.0f),sf::Vector2f(7900.0f, 350.f)));
    dyn_platforms_.push_back(Platforms(&dyn_floor, sf::Vector2f(400.0f,20.0f),sf::Vector2f(10000.0f, 350.f)));
    return dyn_platforms_;
}

std::vector<Platforms> kill_(sf::Texture& water){
    std::vector<Platforms> kill_;
    kill_.push_back(Platforms(&water, sf::Vector2f(12000.0f,300.0f),sf::Vector2f(5500.0f, 700.0f)));
    return kill_;
}

std::vector<Platforms> push_wall_(sf::Texture& wood){
    std::vector<Platforms> push_wall_;
    push_wall_.push_back(Platforms(&wood, sf::Vector2f(30.0f,30.0f),sf::Vector2f(1800.0f, 385.0f)));
    push_wall_.push_back(Platforms(&wood, sf::Vector2f(30.0f,30.0f),sf::Vector2f(3900.0f, 310.0f)));
    return push_wall_;
}

std::vector<Enemy> enemy_(sf::Texture& enemyTexture){
    std::vector<Enemy> enemy_;
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (1050,345)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (2400,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (3400,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (3450,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (5050,445)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (5400,395)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (5750,345)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (8850,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (8900,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (8950,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (9400,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (9450,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (9500,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (9550,295)));
    enemy_.push_back(Enemy (&enemyTexture, sf::Vector2u(3,3),0.2f,sf::Vector2f (9600,295)));
    return enemy_;
}

std::vector<Platforms> win_(sf::Texture& win){
    std::vector<Platforms> win_;
    win_.push_back(Platforms(&win, sf::Vector2f(200.0f,500.0f),sf::Vector2f(10450.0f, 75.0f)));

    return win_;
}

std::vector<sf::Sprite> background_(sf::Texture& background,sf::Texture& hill_,sf::Texture& a,sf::Texture&b){

    std::vector<sf::Sprite> background_;

    sf::Sprite heven;

    sf::Sprite hill;

    sf::Sprite AB;

    sf::Sprite BC;

    heven.setTexture(background);
    heven.setTextureRect(sf::IntRect (0,0,12800,100));
    heven.setPosition(-500,150);


    hill.setTexture(hill_);
    hill.setTextureRect(sf::IntRect (0,0,12800,200));
    hill.setPosition(-500,250);

    AB.setTexture(a);
    AB.setTextureRect(sf::IntRect (0,0,12800,1000));
    AB.setPosition(-500,-260);

    BC.setTexture(b);
    BC.setTextureRect(sf::IntRect (0,0,12800,300));
    BC.setPosition(-500,-100);


    background_.emplace_back(AB);
    background_.emplace_back(BC);
    background_.emplace_back(heven);
    background_.emplace_back(hill);


    return background_;

}



int main()
{

    sf::RenderWindow window(sf::VideoMode(800,600),"Platformer", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f (0.0f, 0.0f),sf::Vector2f(View_Height,View_Height));
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("hero.png"))
    { std::cout<<"UPS.."<<std::endl; }

    bool alive;
    alive=false;

    bool die_;
    die_=false;

    bool winn;
    winn=false;



    Player player(&playerTexture, sf::Vector2u(8,4),0.2f,100.0f, 200.0f);

    Menu menu(window.getSize().x,window.getSize().y);

    Menu die(window.getSize().x,window.getSize().y);

    Menu win(window.getSize().x,window.getSize().y);


    sf::Texture background1;
    if(!background1.loadFromFile("background1.png")) { std::cout<<"UPS.."<<std::endl; }
    background1.setRepeated(true);

    sf::Texture background2;
    if(!background2.loadFromFile("background2.png")) { std::cout<<"UPS.."<<std::endl; }
    background2.setRepeated(true);

    sf::Texture background3;
    if(!background3.loadFromFile("background3.png")) { std::cout<<"UPS.."<<std::endl; }
    background3.setRepeated(true);

    sf::Texture background4;
    if(!background4.loadFromFile("background4.png")) { std::cout<<"UPS.."<<std::endl; }
    background4.setRepeated(true);

    sf::Texture floor;
    if(!floor.loadFromFile("platform.png"))
    { std::cout<<"UPS.."<<std::endl; }
    floor.setRepeated(true);

    sf::Texture dyn_floor;
    if(!dyn_floor.loadFromFile("dyn_platform.png"))
    { std::cout<<"UPS.."<<std::endl; }
    dyn_floor.setRepeated(true);

    sf::Texture water;
    if(!water.loadFromFile("water.png"))
    { std::cout<<"UPS.."<<std::endl; }
    water.setRepeated(true);

    sf::Texture wood;
    if(!wood.loadFromFile("push_wall.png"))
    { std::cout<<"UPS.."<<std::endl; }
    wood.setRepeated(true);

    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("enemy3.png"))
    { std::cout<<"UPS.."<<std::endl; }

    sf::Texture win_texture;
    if(!win_texture.loadFromFile("win.png"))
    { std::cout<<"UPS.."<<std::endl; }


    std::vector<sf::Sprite> background;
    std::vector<Platforms> platforms;
    std::vector<Platforms> dyn_platforms;
    std::vector<Platforms> kill;
    std::vector<Platforms> push_wall;
    std::vector<Enemy> enemy;
    std::vector<Platforms> winer;

    background=background_(background1,background2,background3,background4);
    platforms=platforms_(floor);
    dyn_platforms=dyn_platforms_(dyn_floor);
    kill=kill_(water);
    push_wall=push_wall_(wood);
    enemy=enemy_(enemyTexture);
    winer=win_(win_texture);

    sf::Texture back;
    if(!back.loadFromFile("back.png"))
    { std::cout<<"UPS.."<<std::endl; }
    back.setRepeated(true);


    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 30.0f) {
            deltaTime = 1.0f / 30.0f;
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
        if(!alive) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    alive = true;
                                    break;

                                case 1:
                                    window.close();
                                    break;
                            }
                            break;
                    }
            }
        }


        player.Update(deltaTime);
        for(unsigned int i=0;i<enemy.size();i++) {
            enemy[i].Update(deltaTime);
        }

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
                die_=true;
                alive=false;

            }
        }

        for (Platforms &platform : push_wall) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f,1.0f)) {
                player.OnCollision(direction);

            }
        }

        for (Platforms &platform : winer) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f,1.0f)) {
                player.OnCollision(direction);
                winn=true;
                alive=false;
            }
        }

        auto a=enemy.begin();
        auto b=platforms.begin();

        for(unsigned int i=0;i<enemy.size();i++) {
            enemy[i].Row(1);
            if (enemy[i].GetPosition().x-player.getPosition().x<=120.0f&&enemy[i].GetPosition().x-player.getPosition().x>=60.0f) {
                enemy[i].Move(-0.02,0.0);
                enemy[i].Row(2);
            }
            else if(player.getPosition().x-enemy[i].GetPosition().x<=120.0f&& player.getPosition().x-enemy[i].GetPosition().x>=60.0f) {
                enemy[i].Move(0.02,0.0);
                enemy[i].Row(3);
            }
            enemy[i].Move(0.0,0.0);
            enemy[i].Row(1);

            if(abs(enemy[i].GetPosition().x-player.getPosition().x)<=70.0f){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)||sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    enemy.erase(a + i);

                }
            }
            if(abs(enemy[i].GetPosition().x-player.getPosition().x)<=60.0f){
                die_=true;
                alive=false;
            }
        }



if(alive){
        view.setCenter(player.getPosition());
        window.setView(view);
}
else{
    view.setCenter(400,300);
    window.setView(view);

}
        window.clear(sf::Color::Black);

        if(!alive){

            player.setPosition_();
            menu.Draw(window);
            platforms=platforms_(floor);
            dyn_platforms=dyn_platforms_(dyn_floor);
            kill=kill_(water);
            push_wall=push_wall_(wood);
            enemy=enemy_(enemyTexture);

        }

        if(die_){
            die.Draw_die(window);
        }

        if(winn){
            win.Draw_win(window);
        }

        if(alive) {

            die_=false;
            winn=false;

            for(const auto &back : background)
            {
                window.draw(back);
            }

            player.Draw(window);


            for (Platforms &platforms : platforms) {
                platforms.Draw(window);
            }
            for (Enemy &enemy : enemy) {
                enemy.Draw(window);
            }

            for (Platforms &platforms : dyn_platforms) {
                platforms.Draw(window);
            }
            for (Platforms &platforms : kill) {
                platforms.Draw(window);
            }

            for (Platforms &platforms : push_wall) {
                platforms.Draw(window);
            }

            for (Platforms &platforms : winer) {
                platforms.Draw(window);
            }
        }

        window.display();
    }

    return 0;
}