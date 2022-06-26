#pragma once
#include "main.h"
#include "Player.h"
#include "Room.h"

extern Time dt;
extern RectangleShape background;
void game();
void findCurRoom(std::vector<Room>& map, Room*& currentRoom);
extern float gravity;
extern float playerHeight;
extern Texture playerTexture;
extern vector<Room> rooms;
vector<Room> generateMap(Texture& roomTexture);

void init(Texture& roomTexture);