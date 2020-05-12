#pragma once
#include "Obstacle.h"


class Switch :public Obstacle
{
private:
	float arclength, angle; // Gate arclength
	Vector2D refpoint; // refrence point to position the gate on canvas
	bool passed = false; // Whether or not the ball has passed through the gate before
	float position;  // The horizontal position of the wall
	bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
	Switch(Vector2D refpoint, float arclength, float angle);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	void setpassed(bool passed);
};

