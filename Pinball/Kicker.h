#pragma once
#include "GameObjects/Obstacles/Obstacle.h"
class Kicker : public Obstacle {
private:
	FlipperType type; //Kicker type. too lazy to define a new left or right enum.
	float length, base, top;// basic dimensions.
	Vector2D origin; // the point I use to locate the Kicker on the canvas.

public:
	Kicker();// I don't know what this constructor does SEE AGAIN.

	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;


};

