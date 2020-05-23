#include "Floor.h"
Floor:: Floor(FlipperType type, float length, sf::Vector2f position): type(type), length(length), position(position), collidedLastFrame(false) {}

Vector2D Floor::collideWith(Ball& ball, float collisionTime) {
    bool collide_with_left = ball.getCenter().x - position.x < 0 &&type==LEFT;
    bool collide_with_right = ball.getCenter().x - position.x > 0 && type== RIGHT;
    if (!collidedLastFrame && abs(position.y - ball.getCenter().y) < ball.getRadius() && (collide_with_left|| collide_with_right))
    {
        collidedLastFrame = true;
            return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}

void Floor:: draw(Interface& interface) {
	interface.drawFloor(type, length, position);
}


void Floor::setLength(float length) {
	this->length = length;
}
