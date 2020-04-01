#pragma once
#include"Obstacle.h"

class Bumper: public Obstacle {
private:
	Vector2D center;
	float radius;
	bool coat;


public:
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};