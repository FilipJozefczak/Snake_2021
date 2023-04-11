#pragma once
#include"snake.h"
#include"SFMLView.h"
#include<SFML/Audio.hpp>
#include<iostream>

class SFMLSound
{
	
	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound gameover_sound;
public:
	SFMLSound();
	void play_music();
	void stop_music();
	void play_gameover();
};