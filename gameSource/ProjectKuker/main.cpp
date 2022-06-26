#include "mainMenu.h"
#include "game.h"
const int widthX = VideoMode::getDesktopMode().width;
const int heightY = VideoMode::getDesktopMode().height;

int main()
{	
	srand(time(NULL));
	window.setVerticalSyncEnabled(1);
	game();
}