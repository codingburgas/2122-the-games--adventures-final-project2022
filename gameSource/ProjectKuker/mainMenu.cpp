#include "mainMenu.h"

RenderWindow window(VideoMode(widthX, heightY), "ProjectKuker", Style::Fullscreen);
void mainMenu()
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
	}
}