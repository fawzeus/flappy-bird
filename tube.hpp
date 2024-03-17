#ifndef TUBE_HPP
#define TUBE_HPP
#include <SFML/Graphics.hpp>
#include "CONSTANTS.HPP"
class Tube
{
private:
    double x,y;
    sf::Texture upper_tube,lower_tube;
    sf::Sprite upper_tube_image,lower_tube_image; // the upper and the lower tubes
public:
    Tube(double x=WIDTH, double y=0);
    Tube(const Tube& other);
    Tube operator=(const Tube &other);
    void draw(sf::RenderWindow &window);
    void move();// move the tube
    sf::Sprite get_upper_tube(); // get the upper tube sprite
    sf::Sprite get_lower_tube(); // get the lower tube sprite
    double getX();
};

#endif