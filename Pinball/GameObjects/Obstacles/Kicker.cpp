#include "Kicker.h"

Kicker::Kicker(FlipperType type, Vector2D refpoint, float length, float base, float top): type(type), refpoint(refpoint), length(length), base(base), top(top) {}

Vector2D Kicker::collideWith(Ball& ball, float collisionTime) {
	bool collide_with_left = false;// (ball.getCenter().x - refpoint.x > top && ball.getCenter().x < base);
	bool collide_with_right = false;
	

	bool collide_with_tob_left = - refpoint.x - top + ball.getCenter().x < ball.getRadius() && refpoint.y - ball.getCenter().y < ball.getRadius() && type==LEFT;
	bool collide_with_tob_right = refpoint.x - top - ball.getCenter().x < ball.getRadius() && refpoint.y - ball.getCenter().y < ball.getRadius()&&type == RIGHT;
if (!collidedLastFrame && (collide_with_left || collide_with_right)) {
	
	collidedLastFrame = true;

	return Vector2D{ 4, 5 };
}

else if(!collidedLastFrame && collide_with_tob_left) {
	collidedLastFrame = true;
	return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime;
}

else if (!collidedLastFrame && collide_with_tob_right) {
	collidedLastFrame = true;
	return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime;
}

else {
	collidedLastFrame = false;

	return Vector2D{ 0,0 };
}
}

void Kicker::draw(Interface& ineterface) {
	ineterface.drawKicker(type, refpoint, length, base, top);
}

