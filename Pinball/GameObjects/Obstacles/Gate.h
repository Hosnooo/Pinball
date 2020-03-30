#pragma once
#include "GameObjects/Obstacles/Obstacle.h"
class Gate : public Obstacle
{
private:
	float length, angle; // Gate length & angle
	Vector2D refpoint; // refrence point to position the gate on canvas

public:
	Gate(Vector2D refpoint, float length, float Rotate);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};