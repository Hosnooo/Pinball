#pragma once
#include "Obstacle.h"


class Switch :public Obstacle
{
private:
	float arclength, angle; // Gate arclength
	Vector2D refpoint; // refrence point to position the gate on canvas

public:
	Switch(Vector2D refpoint, float arclength, float angle);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};

