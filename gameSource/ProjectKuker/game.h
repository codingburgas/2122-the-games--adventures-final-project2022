#pragma once
#include "main.h"
#include "Player.h"
#include "Room.h"

extern Time dt;
extern RectangleShape background;
void game();
extern float gravity;
extern float playerHeight;
extern vector<Room> rooms;
vector<Room> generateMap();