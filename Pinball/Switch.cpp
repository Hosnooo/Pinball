#include "Switch.h"

Switch::Switch(Vector2D refpoint, float arclength, float angle): arclength(arclength), refpoint(refpoint), angle(angle){}

void Switch::draw(Interface& interface)
{
	interface.drawSwitch(refpoint, arclength, angle);
};

Vector2D Switch::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D();
}