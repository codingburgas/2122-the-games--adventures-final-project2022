#include "game.h"
Time dt;
float gravity = 1.f;
RectangleShape background(Vector2f(widthX, heightY));
float playerHeight = 2.f * float(VideoMode::getDesktopMode().height) / 16.875f;
vector<Room> rooms;