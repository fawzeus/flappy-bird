#include "bird.hpp"
#include <iostream>



Bird::Bird(double x, double y, double speed ):x(x),y(y),speed(speed){
    bird.loadFromFile("images/bird.png");
	bird_image.setTexture(bird);
    bird_image.setPosition(sf::Vector2f(x,y));
    //change the sprite origin to the center
    bird_image.setOrigin(bird_image.getLocalBounds().width / 2, bird_image.getLocalBounds().height / 2); // Set origin to center of the bird image
    bird_image.setScale(0.25,0.25);
}

void Bird::draw(sf::RenderWindow &window){
    window.draw(bird_image);
}

void Bird::move(){
    speed=-5.5;
    update_position();
    if (bird_image.getRotation()>0)
        bird_image.setRotation(max(0,bird_image.getRotation()-80));//rotate the bird up
    //std::cout<<bird_image.getRotation()<<std::endl;

}
void Bird::gravity(){
    y+=speed;
    speed+=0.2;
    update_position();
    if (bird_image.getRotation()<90)
    bird_image.setRotation(bird_image.getRotation()+1); //rotate the bird down
}
void Bird::update_position(){
    bird_image.setPosition(x,y);
}
