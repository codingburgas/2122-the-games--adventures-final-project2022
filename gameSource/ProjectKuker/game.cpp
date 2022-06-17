#include "game.h"
#include "mainMenu.h"
void game()
{
	Player player(Vector2f(widthX / 2.f, heightY / 2.f), 
				  Vector2f(widthX / 30.f, (heightY / 16.875) * 2),
		          0.03f, "Vanko", 0.25, 0.5, {0.f,0.f});

	Clock deltaClock;
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		Event event;
		while (window.pollEvent(event)) {}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			mainMenu();
		}
		player.playerInput();
		window.clear(Color::White);
		window.draw(player.hitbox);

		window.display();
		
	}
}
