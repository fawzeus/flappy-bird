#include "bird.hpp"
#include "CONSTANTS.HPP"
#include<iostream>
#include <unistd.h>

int main(){
    sf::Texture background;
    background.loadFromFile("images/background.png");
	sf::Sprite background_image(background);
    sf::Texture ground;
    ground.loadFromFile("images/ground.png");
    sf::Sprite ground_image(ground);
    ground_image.setScale(1,0.5);
    ground_image.setPosition(0,650);
    Bird bird(200,100);
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Flappy Bird Game");
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Up){
                    bird.move();
                }
            }
        }
    bird.gravity();
    window.draw(background_image);
    window.draw(ground_image);
    bird.draw(window);
    window.display();
    window.clear();
    usleep(90000);
    }   
}