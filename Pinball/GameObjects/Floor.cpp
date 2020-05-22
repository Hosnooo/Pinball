#include "Floor.h"
Floor:: Floor(FlipperType type, float length, sf::Vector2f position): type(type), length(length), position(position) {}

Vector2D Floor::collideWith(Ball& ball, float collisionTime) {
	return Vector2D{ 0,0 };
}

void Floor:: draw(Interface& interface) {
	interface.drawFloor(type, length, position);
}


void Floor::setLength(float length) {
	this->length = length;
}
