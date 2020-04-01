#pragma once
#include"Obstacle.h"


// the class can draw and support behaviors of all kinds of bumpers based on the initialization of it's attributes.
class Bumper: public Obstacle {
private:
	Vector2D center; // bumper center.
	float radius; //  you guessed it, it's radius.
	bool coat; // wether or not it will have coating.


public:
	Bumper(Vector2D center, float radius, bool coat);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};