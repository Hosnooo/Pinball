#include "Kicker.h"

Kicker::Kicker(FlipperType type, Vector2D refpoint, float length, float base, float top): type(type), refpoint(refpoint), length(length), base(base), top(top) {}

Vector2D Kicker::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D{0,0};
}

void Kicker::draw(Interface& ineterface) {
	ineterface.drawKicker(type, refpoint, length, base, top);
}

