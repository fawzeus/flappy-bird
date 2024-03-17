#ifndef BIRD_HPP
#define BIRD_HPP
#include <SFML/Graphics.hpp>
#define max(a,b) (a>b? a:b)

class Bird{
    private:
        int x,y;
    public:
        sf::Texture bird;
	    sf::Sprite bird_image;
        Bird(int x, int y);
        void draw(sf::RenderWindow &window);
        void move();
        void gravity();
        void update_position();
};

#endif