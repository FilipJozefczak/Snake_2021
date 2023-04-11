#include "menu.h"

#pragma once

menu::menu() 
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Snake");
	startGame = false;
}

void menu::display_menu(sf::RenderWindow&window) 
{
	sf::Font font;
	sf::Text text;

	if (!font.loadFromFile("fonts/Marlboro.ttf"))
		std::cout << "font" << std::endl;

	text.setFont(font);
	text.setString("MEGAWONSZ9");
	text.setCharacterSize(120);
	text.setFillColor(sf::Color::Green);
	text.setPosition(135, 50);
	window.draw(text);


	sf::RectangleShape button;
	button.setSize(sf::Vector2f(400, 100));
	button.setFillColor(sf::Color::Yellow);
	button.setOutlineThickness(4);
	button.setOutlineColor(sf::Color::Red);
	button.setPosition(200, 280);
	window.draw(button);
	button.setPosition(200, 430);
	window.draw(button);


	text.setString("CLASSIC");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);
	text.setPosition(335, 300);
	window.draw(text);

	text.setString("RIVER");
	text.setPosition(350, 440);
	window.draw(text);



	
	
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				

				if (event.mouseButton.x > 200 && event.mouseButton.x < 600)
				{
					if (event.mouseButton.y > 280 && event.mouseButton.y < 380)
					{
						mode = CLASSIC;
						startGame = true;
						std::cout << "przycisk 1\n";
					}

					if (event.mouseButton.y > 430 && event.mouseButton.y < 530)
					{
						mode = RIVER;
						startGame = true;
						std::cout << "przycisk 2\n";
					}
				}
				std::cout << "the left button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				std::cout << "start: " << startGame << std::endl;
				std::cout << "mode: "<< mode << std::endl;
			}
		}

	}

	window.display();
}



Mode menu::getMode()
{
	return mode;
}

bool menu::isGameStarted()
{
	return startGame;
}

