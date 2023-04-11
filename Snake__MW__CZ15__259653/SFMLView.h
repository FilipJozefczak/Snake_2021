#pragma once
#include "snake.h"
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>



class SFMLView
{
    Snake& snake;
    menu& m;
	int cel_size = 20;
    int speed;
    sf::Clock clock;
    sf::Time time;
    


    sf::Texture tail_t;
    sf::Texture head_t;
    sf::Texture apple_t;
    sf::Texture wall_t;
    sf::Texture grass_t;
    sf::Texture water_t;
    sf::Texture bridge_t;
    sf::Texture gameover_t;

    sf::Sprite wall_s;
    sf::Sprite tail_s;
    sf::Sprite head_s;
    sf::Sprite apple_s;
    sf::Sprite field_s;
    //sf::Sprite water_s;
    //sf::Sprite bridge_s;
    sf::Sprite gameover_s;

    sf::Event event;

    sf::Music music;
    sf::SoundBuffer gameover_buffer;
    sf::Sound gameover_sound;

    sf::Font font;
    sf::Text score_txt;
public:
	SFMLView(menu& m, Snake& snake);
	
    
	void play(sf::RenderWindow& window);

	int getCelSize();
    void play_music();
    int getSpeed();
    
    
  
};