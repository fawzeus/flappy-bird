#include "bird.hpp"
#include <iostream>

double max(double a, double b){
    return (a>b? a:b);
}

double min(double a, double b){
    return (a>b? b:a);
}

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
    y=max(y,bird_image.getGlobalBounds().height/2);
    speed+=0.2;
    update_position();
    if (bird_image.getRotation()<90)
    bird_image.setRotation(bird_image.getRotation()+1); //rotate the bird down
}
void Bird::update_position(){
    bird_image.setPosition(x,y);
}

bool Bird::check_collusion(sf::Sprite sp)
{
    return bird_image.getGlobalBounds().intersects(sp.getGlobalBounds());
}

bool Bird::check_tube_collusion(std::vector<Tube> tubes){
    bool res = false;
    //check for collusion between the bird and each tube;
    for(auto tube=tubes.begin();tube!=tubes.end();tube++){
        res |= (x<tube->getX()+tube->get_lower_tube().getGlobalBounds().width/2 and \
                x>tube->getX()-tube->get_lower_tube().getGlobalBounds().width/2-30) and(\
                y<tube->get_upper_tube().getPosition().y+tube->get_upper_tube().getGlobalBounds().height/2+30 or\
                y>tube->get_lower_tube().getPosition().y-tube->get_lower_tube().getGlobalBounds().height/2-30);
        /*
        res |=tube->get_lower_tube().getGlobalBounds().intersects(bird_image.getGlobalBounds()) or \
        tube->get_upper_tube().getGlobalBounds().intersects(bird_image.getGlobalBounds());*/
    }
    return res;
}
double Bird::getX(){
    return x;
}