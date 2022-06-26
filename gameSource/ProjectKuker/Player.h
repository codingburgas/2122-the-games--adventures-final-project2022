#pragma once
#include "main.h"
#include "game.h"
#include "Room.h"
class Player
{
	bool canJump;
	bool faceRight;
	bool fliped;
public:
	RectangleShape hitbox;
	Sprite sprite;
	Texture texture;
	Image textureImage;
	View followPlayer;
	float movementSpeed, crouchMovementSpeed, normalMovementSpeed;
	Vector2f velocity;
	float jumpHeight;
	Player();
	Player(Vector2f pos, Vector2f size, float jumpHeight, Texture& texture,
		float crouchMovementSpeed,
		float normalMovementSpeed, Vector2f velocity);
	void render(RenderTarget* target);

	void playerInput(Room*& currentRoom);
	void checkCollision(Room*& currentRoom);
};
extern Player player;