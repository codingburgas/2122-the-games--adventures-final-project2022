#include "game.h"
#include "mainMenu.h"
void game()
{
	Texture roomTexture;
	init(roomTexture);
	vector<Room> map = generateMap(roomTexture);
	Room* currentRoom = nullptr;
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
		findCurRoom(map, currentRoom);

		player.playerInput(currentRoom);
		
		window.clear(Color::Black);
		
		window.setView(player.followPlayer);
		player.followPlayer.setCenter(player.hitbox.getPosition());
		
		window.draw(currentRoom->boundingBox);
		window.draw(player.hitbox);

		window.display();
	}
}

void findCurRoom(std::vector<Room>& map, Room*& currentRoom)
{
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i].collision(player.hitbox))
		{
			currentRoom = &map[i];
		}
	}
}

vector<Room> generateMap(Texture& roomTexture)
{
	Vector2f rSize(2048, 2048);
	vector<Room> roomMap;
	int rVal = (rand() % 3 + 6), dir = 0, roomI = 0;
	auto room = new Room(rSize, roomTexture);
	
	room->boundingBox.setPosition(widthX / 2, heightY / 2);
	room->boundingBox.setFillColor(Color::White);
	room->boundingBox.setOutlineColor(Color::Black);
	room->boundingBox.setOutlineThickness(5);
	roomMap.push_back(*room);
	delete room;	
	for (int i = 0; i < rVal; i++)
	{
		dir = rand() % 4;
		auto room = new Room(rSize, roomTexture);
		roomI = rand() % roomMap.size();
		while (roomMap[roomI].uFilled && roomMap[roomI].rFilled && roomMap[roomI].dFilled && roomMap[roomI].lFilled)
		{
			
			int oldRoomI = roomI;
			roomI = rand() % roomMap.size();
			if (roomI == oldRoomI)
				continue;
		}
		while ( (roomMap[roomI].uFilled && dir == 0) ||
				(roomMap[roomI].rFilled && dir == 1) ||
				(roomMap[roomI].dFilled && dir == 2) ||
				(roomMap[roomI].lFilled && dir == 3))
		{
			int oldDir = dir;
			dir = rand() % 4;
			if (dir == oldDir)
				continue;
		}

		switch (dir)
		{
		case 0: //Up
			room->boundingBox.setPosition(
				roomMap[roomI].boundingBox.getPosition().x, 
				roomMap[roomI].boundingBox.getPosition().y - rSize.y - 10);
			roomMap[roomI].uFilled = true;
			room->dFilled = true;
			break;
		case 1: //Right
			room->boundingBox.setPosition(
				roomMap[roomI].boundingBox.getPosition().x + rSize.y + 10,
				roomMap[roomI].boundingBox.getPosition().y);
			roomMap[roomI].rFilled = true;
			room->lFilled = true;
			break;
		case 2: //Down
			room->boundingBox.setPosition(
				roomMap[roomI].boundingBox.getPosition().x,
				roomMap[roomI].boundingBox.getPosition().y + rSize.y + 10);
			roomMap[roomI].dFilled = true;
			room->uFilled = true;
			break;
		case 3: //Left
			room->boundingBox.setPosition(
				roomMap[roomI].boundingBox.getPosition().x - rSize.y - 10,
				roomMap[roomI].boundingBox.getPosition().y);
			roomMap[roomI].lFilled = true;
			room->rFilled = true;
			break;
		}
		room->boundingBox.setFillColor(Color::White);
		room->boundingBox.setOutlineColor(Color::Black);
		room->boundingBox.setOutlineThickness(5);
		roomMap.push_back(*room);
		delete room;
	}
	int newDoorChance = 1;
	for (auto it : roomMap)
	{
		rVal = rand() % newDoorChance;
	}
	return roomMap;
}
