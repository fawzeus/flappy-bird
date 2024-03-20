#include "game.hpp"

Game::Game(){
    if (!font.loadFromFile("font/arial.ttf")){
        exit(-1);
    }
    score=0;
    pause=false;
    lost=false;
    background.loadFromFile("images/background.png");
	background_image.setTexture(background);
    ground.loadFromFile("images/ground.png");
    ground_image.setTexture(ground);
}
void Game::play(){
    //crate the game window
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
                    if (!lost and pause){
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
                        draw_score(window);
                        window.display();
                    }
                }
                else if(event.key.code==sf::Keyboard::R){
                    if(lost){
                        init();
                    }
                }
                else if(event.key.code==sf::Keyboard::Q){
                    window.close();
                    exit(0);
                }
            }
        }
    
    //if pause freeze the screen 
    handle_game_over(window);
    if(pause or lost) continue;
    time++;
    //apply gravity on bird
    bird.gravity();
    window.draw(background_image);
    if(time>=rand_int(200,800))
    {
        add_tube();
        time=0;
    }
    update_score();
    delete_old_tubes();
    draw_tubes(window);
    move_tubes();
    window.draw(ground_image);
    draw_score(window);
    bird.draw(window);
    window.display();
    window.clear();
    if(bird.check_collusion(ground_image) or bird.check_tube_collusion(tubes)) lost = true;
    usleep(10000);
    }   
}
void Game::init(){
    bird = Bird();

    tubes.erase(tubes.begin(),tubes.end());
    pause=false;
    score=0;
    lost=false;
    ground_image.setScale(1,0.5);
    ground_image.setPosition(0,650);

}

void Game::add_tube() {

    Tube t(WIDTH+200,rand_int(-50,50));
    //t.print();
    tubes.push_back(t);
}

void Game::draw_tubes(sf::RenderWindow &window){
    for(auto tube=tubes.begin();tube!=tubes.end();tube++){
        tube->draw(window);
    }
}


void Game::delete_old_tubes(){
    if(tubes.size()<1) return;
    if(tubes[0].getX()<-tubes[0].get_upper_tube().getGlobalBounds().width/2){
        tubes.erase(tubes.begin()+0);
    }
}

void Game::move_tubes(){
    for(auto tube=tubes.begin();tube!=tubes.end();tube++){
        tube->move();
    }
}

void Game::draw_score(sf::RenderWindow &window){
    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Score :"+std::to_string(score));
    //text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height/2);

    // set the character size
    text.setCharacterSize(50);
    //set the position to the center
    text.setPosition(20,20);

    // set the color
    text.setFillColor(sf::Color::White);

    // set the text style
    text.setStyle(sf::Text::Bold);
    window.draw(text);
}

void Game::update_score(){
    if(tubes.size()<1)return;
    //tubes[0].print();
    //std::cout<<tubes[0].get_passed()<<std::endl;
    //std::cout<<!tubes[0].get_passed()<<std::endl;
    if(!tubes[0].get_passed() and tubes[0].getX()+tubes[0].get_upper_tube().getGlobalBounds().width/2<bird.getX()){
        score++;
        tubes[0].set_passed();
    }
}

void Game::handle_game_over(sf::RenderWindow &window){
    if (lost){
        sf::Text text1,text2;
        // select the font
        text1.setFont(font); // font is a sf::Font
        text2.setFont(font);
        // set the string to display
        text1.setString("YOU LOST !");
        text2.setString("Press R to play again or Q to quit");
        text1.setCharacterSize(70);
        text2.setCharacterSize(50);
        //set the position to the center
        text1.setPosition(WIDTH/2-text1.getGlobalBounds().width/2,HEIGHT/2-text1.getGlobalBounds().height/2-200);
        text2.setPosition(WIDTH/2-text2.getGlobalBounds().width/2,HEIGHT/2-text2.getGlobalBounds().height/2);
        // set the color
        text1.setFillColor(sf::Color::White);
        // set the text style
        text1.setStyle(sf::Text::Bold);
        window.clear();
        window.draw(background_image);
        draw_tubes(window);
        window.draw(ground_image);
        bird.draw(window);
        window.draw(text1);
        window.draw(text2);
        draw_score(window);
        window.display();
    }
}

int rand_int(int a, int b){
    if (a==b) return a;
    srand(time(0));
    if(a>=0)return rand()%(b-a)+a;
    else{
        if (b>=0){
            return rand()%(b-a)+a;
        }
        else {
            a*=-1;
            b*=-1;
            return -1*rand()%(a-b)+b;
        }
    }
}