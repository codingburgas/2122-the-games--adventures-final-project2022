#include "mainMenu.h"
#include "game.h"

void mainMenu()
{
	RectangleShape play, exit;
	play.setSize(Vector2f(widthX / 5, heightY / 10));
	play.setPosition(Vector2f(widthX / 2 - play.getSize().x, heightY / 2 - play.getSize().y * 2));
	play.setFillColor(Color::Green);
	exit.setSize(Vector2f(widthX / 5, heightY / 10));
	exit.setPosition(Vector2f(widthX / 2 - exit.getSize().x, heightY / 2 + exit.getSize().y * 2));
	exit.setFillColor(Color::Red);
	while (window.isOpen())
	{
		Vector2f mpos = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
		Event event;
		while (window.pollEvent(event)) {}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		
		if (Mouse::isButtonPressed(Mouse::Left) && 
			play.getGlobalBounds().contains(mpos))
		{
			game();
		}
		if (Mouse::isButtonPressed(Mouse::Left) &&
			exit.getGlobalBounds().contains(mpos))
		{
			window.close();
		}

		window.clear(Color::White);
		window.draw(play);
		window.draw(exit);

		window.display();
	}
}