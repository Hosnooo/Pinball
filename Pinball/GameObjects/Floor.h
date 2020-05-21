#pragma once

#include "Obstacles/Obstacle.h"


class Floor: public Obstacle {
private:
	FlipperType type;
	float length;
	float angle;

public:
	Floor(FlipperType type, float length, float angle);

	Vector2D collideWith(Ball& ball, float collisionTime) override;
	
	void draw(Interface& interface) override;
	
	void setAngle(float angle);
	void setLength(float length);
};