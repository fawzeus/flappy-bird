#include "bird.hpp"
#include "tube.hpp"
#include "CONSTANTS.HPP"
#include<iostream>
#include <unistd.h>

int main(){
    bool pause=false;
    sf::Font font;
    if (!font.loadFromFile("font/arial.ttf")){
        std::cout<<"can\'t load font"<<std::endl;
        exit(-1);
    }
    //add the background texture and sprite
    sf::Texture background;
    background.loadFromFile("images/background.png");
	sf::Sprite background_image(background);
    sf::Texture ground;
    ground.loadFromFile("images/ground.png");
    sf::Sprite ground_image(ground);
    //adjust the scale of background
    ground_image.setScale(1,0.5);
    ground_image.setPosition(0,650);
    //create bird object
    Bird bird(200,100);
    Tube tube(WIDTH,50);
    //crate the game window
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Flappy Bird Game");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            //handle buttun pressing event
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Up){
                    bird.move();
                }
                else if(event.key.code==sf::Keyboard::P){
                    pause=!pause;
                    if (pause){
                        sf::Text text;
                        // select the font
                        text.setFont(font); // font is a sf::Font

                        // set the string to display
                        text.setString("Pause");
                        //text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height/2);

                        // set the character size
                        text.setCharacterSize(100);
                        //set the position to the center
                        text.setPosition(WIDTH/2-text.getGlobalBounds().width/2,HEIGHT/2-text.getGlobalBounds().height/2);

                        // set the color
                        text.setFillColor(sf::Color::White);

                        // set the text style
                        text.setStyle(sf::Text::Bold);
                        window.clear();
                        window.draw(background_image);
                        tube.draw(window);
                        window.draw(ground_image);
                        bird.draw(window);
                        window.draw(text);
                        window.display();
                    }
                }
            }
        }
    //if pause freeze the screen 
    if(pause) continue;
    //apply gravity on bird
    bird.gravity();
    window.draw(background_image);
    tube.draw(window);
    tube.move();
    window.draw(ground_image);
    bird.draw(window);
    window.display();
    window.clear();
    usleep(10000);
    }   
}