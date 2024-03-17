#include "bird.hpp"
#include <iostream>



Bird::Bird(int x, int y):x(x),y(y){
    bird.loadFromFile("images/bird.png");
	bird_image.setTexture(bird);
    bird_image.setPosition(sf::Vector2f(x,y));
    bird_image.setOrigin(bird_image.getLocalBounds().width / 2, bird_image.getLocalBounds().height / 2); // Set origin to center of the bird image
    bird_image.setScale(0.25,0.25);
}

void Bird::draw(sf::RenderWindow &window){
    window.draw(bird_image);
}

void Bird::move(){
    y-=100;
    update_position();
    if (bird_image.getRotation()>0)
        bird_image.setRotation(max(0,bird_image.getRotation()-70));
    std::cout<<bird_image.getRotation()<<std::endl;

}
void Bird::gravity(){
    y+=20;
    update_position();
    if (bird_image.getRotation()<90)
    bird_image.setRotation(bird_image.getRotation()+10);
}
void Bird::update_position(){
    bird_image.setPosition(x,y);
}
