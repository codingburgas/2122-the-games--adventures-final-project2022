#pragma once
#include "main.h"
class Room
{
public:
	RectangleShape boundingBox;
	bool uFilled, rFilled, dFilled, lFilled;
	vector<RectangleShape> doors;
	Room();
	Room(Vector2f size, Texture& texture);

	bool collision(RectangleShape& player);
};