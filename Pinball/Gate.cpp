#include "Gate.h"

Gate::Gate(Vector2D refpoint, float length, float angle) : length(length), refpoint(refpoint), angle(angle){}

Vector2D Gate::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D();
}

void Gate::draw(Interface& interface) 
{
	interface.drawGate(refpoint, length, angle);
};