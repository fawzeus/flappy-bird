#ifndef BIRD_HPP
#define BIRD_HPP
#include "tube.hpp"
#include <vector>

class Bird{
    private:
        double x,y,speed;
        sf::Texture bird;
	    sf::Sprite bird_image; //sprite that represent the bird
    public:
        Bird(double x=200, double y=100,double speed =1);
        void draw(sf::RenderWindow &window);//draw bird
        void move();//move the bird up
        void gravity(); //apply gravity on bird
        void update_position();//update the position of bird sprite after moving
        bool check_collusion(sf::Sprite sp); // check for collusion between sprite and the bird
        bool check_tube_collusion(std::vector<Tube> tubes); // check for collusin between bird and Tube (upper and lowers sprites)
};

double max(double a, double b);
double min(double a, double b);
#endif