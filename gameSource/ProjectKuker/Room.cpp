#include "Room.h"

Room::Room(){}
Room::Room(Vector2f size, Texture& texture)
{
	boundingBox.setSize(size);
	boundingBox.setOrigin(boundingBox.getLocalBounds().width/2,
						  boundingBox.getLocalBounds().height / 2);
	//texture.setSmooth(true);
	boundingBox.setTexture(&texture);
	//Room in  direction
	uFilled = false; //up
	rFilled = false; //right
	dFilled = false; //down
	lFilled = false; //left
}

bool Room::collision(RectangleShape& player)
{
	if (boundingBox.getGlobalBounds().contains(player.getPosition()))
		return true;
	return false;
}

