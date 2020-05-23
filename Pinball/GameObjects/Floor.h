#pragma once

#include "Obstacles/Obstacle.h"

class Floor : public Obstacle {
private:
	FlipperType type;
	float length;
	sf::Vector2f position;
	bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
	Floor(FlipperType type, float length, sf::Vector2f position);

	Vector2D collideWith(Ball& ball, float collisionTime) override;
	
	void draw(Interface& interface) override;
	void setLength(float length);
};

