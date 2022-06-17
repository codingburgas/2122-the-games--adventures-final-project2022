#pragma once
#include "main.h"
class Room
{
public:
	Texture texture;
	RectangleShape boundingBox;
	int type;
	int variant;
	Room(int type, int variant);
};