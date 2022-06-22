#pragma once
#include "main.h"
class Room
{
public:
	Texture texture;
	RectangleShape boundingBox;
	int type;
	int variant;
	Vertex connectionPoint;
	string doors;
	Room();
	Room(RectangleShape boundingBox, Texture texture);
	Room(int type, int variant);
};
extern Room r1, r2, r3, r4, r5, r6;
extern vector<Room> leftDoor, rightDoor, topDoor, botDoor;