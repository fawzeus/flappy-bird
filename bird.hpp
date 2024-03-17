#ifndef BIRD_HPP
#define BIRD_HPP
#include <SFML/Graphics.hpp>
#define max(a,b) (a>b? a:b)
#define min(a,b) (a>b? b:a)

class Bird{
    private:
        double x,y,speed;
        sf::Texture bird;
	    sf::Sprite bird_image; //sprite that represent the bird
    public:
        Bird(double x, double y,double speed =1);
        void draw(sf::RenderWindow &window);//draw bird
        void move();//move the bird up
        void gravity(); //apply gravity on bird
        void update_position();//update the position of bird sprite after moving
};

#endif