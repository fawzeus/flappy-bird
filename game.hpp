#ifndef GAME_HPP
#define GAME_HPP
#include "game.hpp"
#include "bird.hpp"
#include <vector>
#include <unistd.h>
#include <thread>
#include <iostream>
class Game {
    private:
        int score;
        Bird bird;
        std::vector<Tube> tubes; // vector that represent the tubes
        sf::Texture background; 
        sf::Sprite background_image; 
        sf::Texture ground;
        sf::Sprite ground_image;
        sf::Font font;
        bool pause=false; // variable that indicate if game is paused
    public:
        Game();
        void init(); // init sprites of game
        void add_tube(); // add a new tube to the tubes vector
        void play(); // start playing
        void draw_tubes(sf::RenderWindow &window); // draw all tubes
        void delete_old_tubes(); //delete the tubes that goes out of screen
        void move_tubes(); // move the tubes
        void draw_score(sf::RenderWindow &window); // draw the score of the player
        void update_score(); //update the score
};



#endif