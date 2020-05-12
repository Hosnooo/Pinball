#pragma once
#include "Obstacle.h"
class Switch : public Obstacle
{
private:
	float length, angle; // Gate length & angle
	Vector2D refpoint; // refrence point to position the gate on canvas
	bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
	Switch(Vector2D refpoint, float length, float angle);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};