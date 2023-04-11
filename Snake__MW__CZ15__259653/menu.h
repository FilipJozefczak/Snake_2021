#pragma once


#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
enum Mode {CLASSIC, RIVER };

class menu
{
	
	Mode mode;
	bool startGame;

public:
	menu();
	void display_menu(sf::RenderWindow&window);

	Mode getMode();
	bool isGameStarted();

};