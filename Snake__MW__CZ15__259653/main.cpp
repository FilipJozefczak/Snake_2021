//Filip Jozefczak

#include <iostream>
#include "snake.h"
#include "SFMLView.h"
#include "SFMLSound.h"
#include "menu.h"

int main()
{

	srand(time(0));
	menu m;
	Snake s(m);

	
	/*s.debug_display();
	s.turn(LEFT);
	s.update();
	s.debug_display();
	s.turn(UP);
	s.update();
	s.debug_display();
	s.update();
	s.debug_display();*/
	SFMLView view(m, s);
	
	sf::RenderWindow win(sf::VideoMode(s.getBoardWidth() * view.getCelSize() , s.getBoardHeight() * view.getCelSize() + 3*view.getCelSize()), "Snake by Filip Jozefczak");

	view.play_music();
	
	while (win.isOpen())
	{
		if (!m.isGameStarted())
		{
			m.display_menu(win);
			s.choose_gamemode();
		}
		if (m.isGameStarted())
		{
			win.clear(sf::Color(0, 0, 0));
			view.play(win);
		}
		
	}
	

}