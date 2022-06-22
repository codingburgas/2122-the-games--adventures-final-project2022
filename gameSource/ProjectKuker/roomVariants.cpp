#include "Room.h"

Room r1 = { RectangleShape(Vector2f(2000,1500)), Texture() },
	 r2 = { RectangleShape(Vector2f(4000,750)), Texture() },
	 r3 = { RectangleShape(Vector2f(1500,4000)), Texture() },
	 r4 = { RectangleShape(Vector2f(2000,1500)), Texture() },
	 r5 = { RectangleShape(Vector2f(2000,4000)), Texture() },
	 r6 = { RectangleShape(Vector2f(2000,1500)), Texture() };

vector<Room> leftDoor  = {r1,r2,r3,r4,r6},
			 rightDoor = {r1,r2,r3,r4,r5},
			 topDoor   = {r2,r3,r5},
			 botDoor   = {r3};
