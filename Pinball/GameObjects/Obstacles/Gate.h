#pragma once
#include "Obstacle.h"


class Gate :public Obstacle
{
private:
	float arclength, angle; // Gate arclength
	Vector2D refpoint; // refrence point to position the switch on canvas
	bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
	Gate(Vector2D refpoint, float arclength, float angle);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};

