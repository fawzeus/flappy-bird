#include "tube.hpp"

Tube::Tube(double x, double y):x(x),y(y){
    tube.loadFromFile("images/tube.png");
    upper_tube_image.setTexture(tube);
    lower_tube_image.setTexture(tube);
    upper_tube_image.setOrigin(upper_tube_image.getGlobalBounds().width/2,upper_tube_image.getGlobalBounds().height/2);
    lower_tube_image.setOrigin(lower_tube_image.getGlobalBounds().width/2,lower_tube_image.getGlobalBounds().height/2);
    upper_tube_image.rotate(180);
    upper_tube_image.setPosition(x,y);
    lower_tube_image.setPosition(x,y+lower_tube_image.getGlobalBounds().height+200);
}
void Tube::draw(sf::RenderWindow &window){
    window.draw(upper_tube_image);
    window.draw(lower_tube_image);
}

void Tube::move(){
    x-=2;
    upper_tube_image.setPosition(x,y);
    lower_tube_image.setPosition(x,y+lower_tube_image.getGlobalBounds().height+200);
}