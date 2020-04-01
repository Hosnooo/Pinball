#include "Bumper.h"


void Bumper:: draw(Interface& interface) {
	interface.drawBumper(center, radius, coat);
}

Vector2D Bumper::collideWith(Ball& ball, float collisionTime)
{
	return {0,0};
}
