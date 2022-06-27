#include "game.h"
#include "mainMenu.h"
void game()
{
	init();

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
		window.clear(Color::Black);
		
		window.setView(player.followPlayer);
		player.followPlayer.setCenter(player.hitbox.getPosition());
		window.draw(background);
		window.draw(player.hitbox);

		window.display();
		//window.setView(window.getDefaultView());
	}
}

vector<Room> generateMap()
{
	vector<Room> roomMap;
	int rVal = rand() % 3 + 6;

	for (int i = 0; i < rVal; i++)
	{
		rVal = rand() % 6 + 1;
		int roomsFromCur = 1;
		auto room = new Room;
		roomMap.push_back(*room);
		delete room;
	}
	return roomMap;
}
