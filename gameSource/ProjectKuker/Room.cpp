#include "Room.h"

Room::Room(){}
Room::Room(RectangleShape boundingBox, Texture texture = {})
{
	this->boundingBox = boundingBox;
	this->texture = texture;
}

