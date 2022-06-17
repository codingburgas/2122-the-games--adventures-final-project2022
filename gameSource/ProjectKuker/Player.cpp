#include "Player.h"

Player::Player(Vector2f pos, Vector2f size, float jumpHeight, string name = "Vanko",
	float crouchMovementSpeed = 0.25f, float normalMovementSpeed = 0.5f, Vector2f velocity = {0,0})
{
	hitbox.setSize(size);
	hitbox.setPosition(pos);
	hitbox.setFillColor(Color::Green);
	canJump = 1;
	this->jumpHeight = jumpHeight;
	this->name = name;
	this->movementSpeed = normalMovementSpeed;
	this->velocity  = velocity;
	this->crouchMovementSpeed = crouchMovementSpeed;
	this->normalMovementSpeed = normalMovementSpeed;
}

void Player::render(RenderTarget * target)
{
	target->draw(this->hitbox);
}

void Player::playerInput()
{
	velocity.x = 0.f;

	if (Keyboard::isKeyPressed(Keyboard::W) && canJump)
	{
		canJump = 0;
		velocity.y = -sqrtf(2.f * gravity * jumpHeight * playerHeight);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		hitbox.setSize(Vector2f(hitbox.getSize().x, playerHeight / 2));
		movementSpeed = crouchMovementSpeed;
	}
	else
	{
		hitbox.setSize(Vector2f(hitbox.getSize().x, playerHeight));
		movementSpeed = normalMovementSpeed;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		velocity.x -= movementSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x += movementSpeed;
	}

	velocity.y += gravity * float(dt.asSeconds()*10);
	hitbox.move(velocity * float(dt.asMilliseconds()));
	checkScreenCollision();
}

void Player::checkScreenCollision()
{
	if (hitbox.getPosition().x < 0)
	{
		hitbox.setPosition(0, hitbox.getPosition().y);
	}
	if (hitbox.getPosition().y < 0)
	{
		hitbox.setPosition(hitbox.getPosition().x, 0);
	}

	if (hitbox.getPosition().x + hitbox.getSize().x > widthX)
	{
		hitbox.setPosition(widthX - hitbox.getSize().x, hitbox.getPosition().y);
	}
	if (hitbox.getPosition().y + hitbox.getSize().y > heightY)
	{
		hitbox.setPosition(hitbox.getPosition().x, heightY - hitbox.getSize().y);
		canJump = 1;
	}
}
