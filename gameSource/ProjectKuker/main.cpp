#include "mainMenu.h"
#include "game.h"
const int widthX = VideoMode::getDesktopMode().width;
const int heightY = VideoMode::getDesktopMode().height;

int main()
{	window.setFramerateLimit(144);
	mainMenu();
}