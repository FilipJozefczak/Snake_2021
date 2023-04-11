#include "SFMLSound.h"

SFMLSound::SFMLSound()
{

	music.setLoop(true);
	
}

void SFMLSound::play_music()
{
	if (!music.openFromFile("C:\\Users\\Juzio\\source\\repos\\Snake__MW__CZ15__259653\\Debug\\audio\\tududu.ogg"))
	std::cout << "tududu" << std::endl;

	
	music.play();
}

void SFMLSound::stop_music()
{
	music.stop();
}

void SFMLSound::play_gameover()
{
	if (!buffer.loadFromFile("C:\\Users\\Juzio\\source\\repos\\Snake__MW__CZ15__259653\\Debug\\audio\\GOsound.ogg"))
		std::cout << "same over sound" << std::endl;

	
	gameover_sound.setBuffer(buffer);
	gameover_sound.play();
}
