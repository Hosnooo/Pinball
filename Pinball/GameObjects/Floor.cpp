#include "Floor.h"
Floor:: Floor(FlipperType type, float length, float angle): type(type), length(length), angle(angle) {}

Vector2D Floor::collideWith(Ball& ball, float collisionTime) {
	return Vector2D{ 0,0 };
}

void Floor:: draw(Interface& interface) {
	interface.drawFloor(length, angle, type);
}

void Floor:: setAngle(float angle) {
	this->angle=angle;

}

void Floor:: setLength(float length) {
	this->length = length;
}
