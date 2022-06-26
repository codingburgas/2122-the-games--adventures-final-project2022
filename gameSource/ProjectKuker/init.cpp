#include "game.h"
Time dt;
float gravity = 4000.f;
RectangleShape background(Vector2f(widthX, heightY));
float playerHeight = 2.f * float(VideoMode::getDesktopMode().height) / 16.875f;
vector<Room> rooms;
Player player;
Texture playerTexture;

void init(Texture& roomTexture)
{
	playerTexture.loadFromFile("Images/kuker.png");
	player = { Vector2f(widthX / 2.f, heightY / 2.f),
			   Vector2f(widthX / 30.f, (heightY / 16.875) * 2),
			   2.f, playerTexture, 50.f, 150, { 0.f,0.f }};

	roomTexture.loadFromFile("Images/roomBG.png");
	background.setSize(Vector2f(widthX, heightY));
	background.setFillColor(Color::White);
	background.setOutlineThickness(1);
	background.setOutlineColor(Color::White);
}