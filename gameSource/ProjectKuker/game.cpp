#include "game.h"
#include "mainMenu.h"
void game()
{
	Player player(Vector2f(widthX / 2.f, heightY / 2.f), 
				  Vector2f(widthX / 30.f, (heightY / 16.875) * 2),
		          0.03f, "Vanko", 0.15, 0.40, {0.f,0.f});
	background.setSize(Vector2f(widthX, heightY));
	background.setFillColor(Color::White);
	background.setOutlineThickness(1);
	background.setOutlineColor(Color::White);
	

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
		auto room = new Room(rVal, 0);
		if (room->doors.find("l") != string::npos && !(rand() % roomsFromCur))
		{
			roomsFromCur++;
		}
		if (room->doors.find("r") != string::npos && !(rand() % roomsFromCur))
		{
			roomsFromCur++;
		}
		if(room->doors.find("t") != string::npos && !(rand() % roomsFromCur))
		{
			roomsFromCur++;
		}
		if (room->doors.find("b") != string::npos && !(rand() % roomsFromCur))
		{
			roomsFromCur++;
		}
		roomMap.push_back(*room);
		delete room;
	}
	return roomMap;
}
