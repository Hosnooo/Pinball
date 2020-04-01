#pragma once
#include "Obstacle.h"
class Kicker : public Obstacle {
private:
	FlipperType type; //Kicker type. too lazy to define a new left or right enum.
	float length, base, top;// basic dimensions.
	Vector2D refpoint; // the point I use to locate the Kicker on the canvas. The top right point for the right flipper.

public:
	Kicker(FlipperType type, Vector2D refpoint, float length, float base, float top);// I don't know what this constructor does SEE AGAIN.

	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;


};

