#include "game.hpp"

Game::Game(){
    if (!font.loadFromFile("font/arial.ttf")){
        exit(-1);
    }
    background.loadFromFile("images/background.png");
	background_image.setTexture(background);
    ground.loadFromFile("images/ground.png");
    ground_image.setTexture(ground);
}
void Game::play(){
    //crate the game window
    srand(time(0));
    int time=0;
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
                        draw_tubes(window);
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
    time++;
    //apply gravity on bird
    bird.gravity();
    window.draw(background_image);
    if(time>= rand()%500+300)
    {
        add_tube();
        time=0;
    }
    delete_old_tubes();
    draw_tubes(window);
    move_tubes();
    window.draw(ground_image);
    bird.draw(window);
    window.display();
    window.clear();
    if(bird.check_collusion(ground_image)) break;
    usleep(10000);
    }   
}
void Game::init(){
    ground_image.setScale(1,0.5);
    ground_image.setPosition(0,650);
}

void Game::add_tube() {
    tubes.push_back(Tube());
}

void Game::draw_tubes(sf::RenderWindow &window){
    for(auto tube=tubes.begin();tube!=tubes.end();tube++){
        tube->draw(window);
    }
}

void Game::delete_old_tubes(){
    std::vector<int> indexes;
    for(unsigned long i=0;i<tubes.size();i++){
        if(tubes[i].getX()<0){
            indexes.push_back(i);
        }
    }
    for (auto index=indexes.begin();index!=indexes.end();index++){
        tubes.erase(tubes.begin()+*index);
    }
}

void Game::move_tubes(){
    for(auto tube=tubes.begin();tube!=tubes.end();tube++){
        tube->move();
    }
}