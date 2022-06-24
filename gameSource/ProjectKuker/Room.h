#pragma once
#include "main.h"
class Room
{
public:
	Texture texture;
	RectangleShape boundingBox;
	int type;
	vector<Vertex> doorPoints;
	string doors;
	Room();
	Room(RectangleShape boundingBox, Texture texture);
};