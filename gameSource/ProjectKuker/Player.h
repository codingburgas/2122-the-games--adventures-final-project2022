#pragma once
#include "main.h"
#include "game.h"
class Player
{
	bool canJump;
public:
	RectangleShape hitbox;
	Sprite sprite;
	Texture texture;
	View followPlayer;
	float movementSpeed, crouchMovementSpeed, normalMovementSpeed;
	Vector2f velocity;
	float jumpHeight;
	Player();
	Player(Vector2f pos, Vector2f size, float jumpHeight,
		float crouchMovementSpeed,
		float normalMovementSpeed, Vector2f velocity);
	void render(RenderTarget* target);

	void playerInput();
	void checkScreenCollision();
};
extern Player player;