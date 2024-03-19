#include "tube.hpp"

Tube::Tube(double x, double y,bool passed):x(x),y(y),passed(passed){
    upper_tube.loadFromFile("images/tube.png");
    lower_tube.loadFromFile("images/tube.png");
    upper_tube_image.setTexture(upper_tube);
    lower_tube_image.setTexture(lower_tube);
    upper_tube_image.setOrigin(upper_tube_image.getGlobalBounds().width/2,upper_tube_image.getGlobalBounds().height/2);
    lower_tube_image.setOrigin(lower_tube_image.getGlobalBounds().width/2,lower_tube_image.getGlobalBounds().height/2);
    upper_tube_image.setPosition(x,y);
    upper_tube_image.setRotation(180);
    lower_tube_image.setPosition(x+100,y+lower_tube_image.getGlobalBounds().height+250);
}
Tube::Tube(const Tube &other){
    x=other.x;
    y=other.y;
    upper_tube=other.upper_tube;
    lower_tube=other.lower_tube;
    lower_tube_image.setTexture(lower_tube);
    upper_tube_image.setTexture(upper_tube);
    upper_tube_image.setOrigin(upper_tube_image.getGlobalBounds().width/2,upper_tube_image.getGlobalBounds().height/2);
    lower_tube_image.setOrigin(lower_tube_image.getGlobalBounds().width/2,lower_tube_image.getGlobalBounds().height/2);
    upper_tube_image.setRotation(180);
    upper_tube_image.setPosition(x,y);
    lower_tube_image.setPosition(x+100,y+lower_tube_image.getGlobalBounds().height+250);

}

Tube Tube::operator=(const Tube &other){
    if(this!=&other){
        x=other.x;
        y=other.y;
        upper_tube=other.upper_tube;
        lower_tube=other.lower_tube;
        lower_tube_image.setTexture(lower_tube);
        upper_tube_image.setTexture(upper_tube);
        upper_tube_image.setOrigin(upper_tube_image.getGlobalBounds().width/2,upper_tube_image.getGlobalBounds().height/2);
        lower_tube_image.setOrigin(lower_tube_image.getGlobalBounds().width/2,lower_tube_image.getGlobalBounds().height/2);
        upper_tube_image.setRotation(180);
        upper_tube_image.setPosition(x,y);
        lower_tube_image.setPosition(x+100,y+lower_tube_image.getGlobalBounds().height+250);
    }
    return *this;
}

void Tube::draw(sf::RenderWindow &window){
    window.draw(upper_tube_image);
    window.draw(lower_tube_image);
}

void Tube::move(){
    x-=2;
    upper_tube_image.setPosition(x,y);
    lower_tube_image.setPosition(x,y+lower_tube_image.getGlobalBounds().height+250);
}

sf::Sprite Tube::get_upper_tube(){
    return upper_tube_image;
}
sf::Sprite Tube::get_lower_tube(){
    return lower_tube_image;
}
double Tube::getX(){
    return x;
}
double Tube::getY(){
    return y;
}

void Tube::set_passed(){
    passed=true;
}

bool Tube::get_passed(){
    return passed;
}