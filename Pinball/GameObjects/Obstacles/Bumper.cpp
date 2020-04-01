#include "Bumper.h"

Bumper::Bumper(Vector2D center, float radius, bool coat=0) : center(center), radius(radius), coat(coat) {}

void Bumper:: draw(Interface& interface) {
	interface.drawBumper(center, radius, coat);
}

Vector2D Bumper::collideWith(Ball& ball, float collisionTime)
{
	return {0,0};
}
