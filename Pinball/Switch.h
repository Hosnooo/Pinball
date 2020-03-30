#pragma once
#include "GameObjects/Obstacles/Obstacle.h"


};
class Switch
{
private:
	float length, angle; // Gate length & angle
	Vector2D refpoint; // refrence point to position the gate on canvas

public:
	Switch(Vector2D refpoint, float length, float Rotate);
};

