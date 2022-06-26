#include "Player.h"
Player::Player() {}
Player::Player(Vector2f pos, Vector2f size, float jumpHeight, Texture& texture,
	float crouchMovementSpeed = 0.25f, float normalMovementSpeed = 0.5f, Vector2f velocity = { 0,0 })
{
	faceRight = true;
	canJump = false;
	fliped = false;
	hitbox.setSize(size);
	hitbox.setPosition(pos);
	hitbox.setFillColor(Color::White);
	hitbox.setTexture(&texture);
	
	this->jumpHeight = jumpHeight;
	this->movementSpeed = normalMovementSpeed;
	this->velocity  = velocity;
	this->crouchMovementSpeed = crouchMovementSpeed;
	this->normalMovementSpeed = normalMovementSpeed;

	followPlayer.setCenter(hitbox.getPosition().x+widthX / 3, hitbox.getPosition().y+heightY/3);
	followPlayer.setSize(Vector2f(widthX*.8,heightY*.8));
}

void Player::render(RenderTarget * target)
{
	target->draw(this->hitbox);
}

void Player::playerInput(Room*& currentRoom)
{
	if (canJump) {
		velocity.x *= .8;
	}

	if (velocity.x > 3*movementSpeed && velocity.x > 0)
		velocity.x = 3*movementSpeed;
	else if(velocity.x < 3 * -movementSpeed && velocity.x < 0)
		velocity.x = 3 * -movementSpeed;

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
		faceRight = false;

		if (canJump)
			velocity.x -= movementSpeed;
		else
			velocity.x -= crouchMovementSpeed;

	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		faceRight = true;
		if (canJump)
			velocity.x += movementSpeed;
		else
			velocity.x += crouchMovementSpeed;
	}

	velocity.y += gravity * float(dt.asSeconds());
	hitbox.move(velocity * float(dt.asSeconds()));
	if (faceRight)
	{
		if (fliped)
		{
			textureImage = hitbox.getTexture()->copyToImage();
			textureImage.flipHorizontally();
			texture.loadFromImage(textureImage);
			hitbox.setTexture(&texture);
			fliped = 0;
		}
	}
	else
	{
		if (!fliped) 
		{
			textureImage = hitbox.getTexture()->copyToImage();
			textureImage.flipHorizontally();
			texture.loadFromImage(textureImage);
			hitbox.setTexture(&texture);
			fliped = 1;
		}
	}

	player.checkCollision(currentRoom);
}

void Player::checkCollision(Room *&currentRoom)
{
	if (hitbox.getPosition().x < currentRoom->boundingBox.getPosition().x - currentRoom->boundingBox.getSize().x / 2)
	{
		hitbox.setPosition(currentRoom->boundingBox.getPosition().x - currentRoom->boundingBox.getSize().x / 2, hitbox.getPosition().y);
		(!canJump) ? velocity.x = -velocity.x / 2 : 0;
	}
	if (hitbox.getPosition().y < currentRoom->boundingBox.getPosition().y - currentRoom->boundingBox.getSize().y / 2)
	{
		hitbox.setPosition(hitbox.getPosition().x, currentRoom->boundingBox.getPosition().y - currentRoom->boundingBox.getSize().y / 2);
	}
	if (hitbox.getPosition().x + hitbox.getSize().x > currentRoom->boundingBox.getPosition().x + currentRoom->boundingBox.getSize().x / 2)
	{
		hitbox.setPosition(currentRoom->boundingBox.getPosition().x + currentRoom->boundingBox.getSize().x / 2 - hitbox.getSize().x , hitbox.getPosition().y);
		(!canJump) ? velocity.x = -velocity.x / 2 : 0;
	}
	if (hitbox.getPosition().y + hitbox.getSize().y > currentRoom->boundingBox.getPosition().y + currentRoom->boundingBox.getSize().y / 2)
	{
		hitbox.setPosition(hitbox.getPosition().x, currentRoom->boundingBox.getPosition().y + currentRoom->boundingBox.getSize().y / 2 - hitbox.getSize().y);
		canJump = 1;
	}
}
