#include "Room.h"

Room::Room(){}
Room::Room(RectangleShape boundingBox, Texture texture = {})
{
	this->boundingBox = boundingBox;
	this->texture = texture;
}

Room::Room(int type, int variant)
{
	this->type = type;
	this->variant = variant;
	
	switch (type)
	{
	case 1:
		this->boundingBox = r1.boundingBox;
		this->texture = r1.texture;
		this->doors = "lr";
		break;
	case 2:
		this->boundingBox = r2.boundingBox;
		this->texture = r1.texture;
		this->doors = "lrt";
		break;
	case 3:
		this->boundingBox = r3.boundingBox;
		this->texture = r1.texture;
		this->doors = "lrtb";
		break;
	case 4:
		this->boundingBox = r4.boundingBox;
		this->texture = r1.texture;
		this->doors = "lr";
		break;
	case 5:
		this->boundingBox = r5.boundingBox;
		this->texture = r1.texture;
		this->doors = "rt";
		break;
	case 6:
		this->boundingBox = r6.boundingBox;
		this->texture = r1.texture;
		this->doors = "l";
		break;
	default:
		break;
	}
}
