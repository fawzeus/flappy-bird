#ifndef TUBE_HPP
#define TUBE_HPP
#include <SFML/Graphics.hpp>

class Tube
{
private:
    double x,y;
    sf::Texture tube;
    sf::Sprite upper_tube_image,lower_tube_image; // the upper and the lower tubes
public:
    Tube(double x, double y);
    void draw(sf::RenderWindow &window);
    void move();// move the tube
};

#endif