#include "SFMLView.h"
#include<iostream>

SFMLView::SFMLView(menu& m, Snake& snake) : snake(snake), m(m)
{
    
	sf::RenderWindow window(sf::VideoMode(600, 600), "Snake");

    speed = 100;
}





void SFMLView::play(sf::RenderWindow& window)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::W)
            {
                if (snake.getDirection() != DOWN && snake.getDirection() != STOP)
                    snake.turn(UP);
            }
            if (event.key.code == sf::Keyboard::S)
            {
                if (snake.getDirection() != UP && snake.getDirection() != STOP)
                    snake.turn(DOWN);
            }
            if (event.key.code == sf::Keyboard::A)
            {
                if (snake.getDirection() != RIGHT && snake.getDirection() != STOP)
                    snake.turn(LEFT);
            }
            if (event.key.code == sf::Keyboard::D)
            {
                if (snake.getDirection() != LEFT && snake.getDirection() != STOP)
                    snake.turn(RIGHT);
            }
            if (event.key.code == sf::Keyboard::R)
            {
                snake.restart();
                speed = 100;
                music.stop();
                music.play();
            }
            if (event.key.code == sf::Keyboard::P)
            {
                music.stop();
                std::cout << "PAUSED" << std::endl;

                sf:sleep(sf::seconds(5));
                music.play();
            }
            if (event.key.code == sf::Keyboard::X)
            {
                window.close();
            }
        }
    }

    time = clock.getElapsedTime();


        if (!tail_t.loadFromFile("sprites/tail.png"))
        std::cout << "tail" << std::endl;
        if (!head_t.loadFromFile("sprites/head.png"))
        std::cout << "head" << std::endl;
        if (!apple_t.loadFromFile("sprites/apple.png"))
        std::cout << "apple" << std::endl;
        if (!wall_t.loadFromFile("sprites/wall.png"))
        std::cout << "wall" << std::endl;
        if (!grass_t.loadFromFile("sprites/grass.png"))
        std::cout << "grass" << std::endl;
        if (!gameover_t.loadFromFile("sprites/gameover.png"))
            std::cout << "go" << std::endl;
        if (!water_t.loadFromFile("sprites/water.png"))
            std::cout << "water" << std::endl;
        if (!bridge_t.loadFromFile("sprites/bridge.png"))
            std::cout << "bridge" << std::endl;

        

    tail_s.setTexture(tail_t);
    head_s.setTexture(head_t);
    apple_s.setTexture(apple_t);
    wall_s.setTexture(wall_t);
  
    gameover_s.setTexture(gameover_t);

 
   

    if (!font.loadFromFile("fonts/Marlboro.ttf"))
        std::cout << "font" << std::endl;

    score_txt.setFont(font);
    score_txt.setString("PUNKTY: " + std::to_string(snake.getScore()));
    score_txt.setCharacterSize(26);
    score_txt.setFillColor(sf::Color(255,0,0));
    
    if(m.getMode() == CLASSIC)
        for (int i = 0; i < snake.getBoardWidth(); ++i)
        {
            for (int j = 0; j < snake.getBoardHeight() + 3; ++j)
            {
                if (i == 0 || i == snake.getBoardWidth() - 1 || j == 0 || j == snake.getBoardHeight() + 2 || j == 1 || j == 2 || j == 3)
                {

                    if (i > snake.getBoardWidth() - 12 && i < snake.getBoardHeight() - 4 && j>0 && j < 3)
                    {
                    }
                    else {
                        wall_s.setPosition(i * cel_size, j * cel_size);
                        window.draw(wall_s);
                    }
                }

                else
                {
                    field_s.setTexture(grass_t);
                    field_s.setPosition(i * cel_size, j * cel_size);
                    window.draw(field_s);
                }
            }
        }

    if(m.getMode() == RIVER)
        for (int i = 0; i < snake.getBoardWidth(); ++i)
        {
            for (int j = 0; j < snake.getBoardHeight() + 3; ++j)
            {
                if (i == 0 || i == snake.getBoardWidth() - 1 || j == 0 || j == snake.getBoardHeight() + 2 || j == 1 || j == 2 || j == 3)
                {

                    if (i > snake.getBoardWidth() - 12 && i < snake.getBoardHeight() - 4 && j>0 && j < 3)
                    {
                    }
                    else {
                        wall_s.setPosition(i * cel_size, j * cel_size);
                        window.draw(wall_s);
                    }
                }

                else
                {
                    if (i > snake.getBoardWidth() / 2 - 3 && i < snake.getBoardWidth() / 2 + 3)
                    {
                        
                        
                            if ((j > 7 && j < 11) || (j < snake.getBoardHeight()-2   && j > snake.getBoardHeight() - 6))
                            {
                                field_s.setTexture(bridge_t);
                                
                            }
                            else
                            {
                                field_s.setTexture(water_t);
                                
                            }
                        
                    }
                    else
                    {
                        field_s.setTexture(grass_t);
                        
                    }
                    field_s.setPosition(i * cel_size, j * cel_size);
                    window.draw(field_s);
                }
                
                
            }
        }
    
    if (snake.getScore() > 30)
        speed = 90;
    if (snake.getScore() > 60)
        speed = 80;
    if (snake.getScore() > 90)
        speed = 70;
    if (snake.getScore() > 120)
        speed = 60;
    if (snake.getScore() > 150)
        speed = 50;
    if (snake.getScore() > 190)
        speed = 40;
    if (snake.getScore() > 240)
        speed = 35;
    if (snake.getScore() > 290)
        speed = 30;
    if (snake.getScore() > 390)
        speed = 25;
    if (snake.getScore() > 490)
        speed = 20;
    if (snake.getScore() > 990)
        speed = 15;
    if (snake.getScore() > 1990)
        speed = 10;

    

    
    
        if (time.asMilliseconds()>=speed)
        {
            if (snake.isGameOver() == true)
            {
               
               
               

                window.clear(sf::Color(0, 0, 0));
                gameover_s.setPosition(snake.getBoardHeight() / 2 -25, snake.getBoardWidth() / 2 + 50);
                window.draw(gameover_s);
                window.display();

            }
            
            else {
                if (snake.getDirection() == RIGHT || snake.getDirection() == LEFT)
                {
                    head_s.setRotation(270.f);
                    head_s.setPosition((snake.getSnakePosX(0)* cel_size), (snake.getSnakePosY(0)* cel_size + cel_size));
                    window.draw(head_s);
                }

                else
                {
                    head_s.setRotation(0.f);
                    head_s.setPosition((snake.getSnakePosX(0) * cel_size), (snake.getSnakePosY(0) * cel_size));
                    window.draw(head_s);
                }

                for (int i = 1; i < snake.getSnakeSize(); ++i)
                {
                    tail_s.setPosition((snake.getSnakePosX(i) * cel_size), (snake.getSnakePosY(i) * cel_size));
                    window.draw(tail_s);
                }

                apple_s.setPosition((snake.getFruitPosX() * cel_size), (snake.getFruitPosY() * cel_size));
                window.draw(apple_s);
                score_txt.setPosition(snake.getBoardWidth() * cel_size - 200,  cel_size+4);
                window.draw(score_txt);

                snake.update();
                window.display();
                clock.restart();
            }
            
          
            
        }
       
    
  }
    
 


int SFMLView::getCelSize()
{
    return cel_size;
}

void SFMLView::play_music()
{
    if (!music.openFromFile("audio/Corona-320bit.ogg"))
        std::cout << "background music" << std::endl;
    music.setVolume(60);
    music.setLoop(true);
    music.play();

    //Corona by Alexander Nakarada | https://www.serpentsoundstudios.com
    //Music promoted by https ://www.chosic.com/
    //Attribution 4.0 International(CC BY 4.0)
    //    https ://creativecommons.org/licenses/by/4.0/
}

int SFMLView::getSpeed()
{
    return speed;
}







