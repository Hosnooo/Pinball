#include "Floor.h"
Floor:: Floor(FlipperType type, float length, sf::Vector2f position): type(type), length(length), position(position), collidedLastFrame(false) {}

Vector2D Floor::collideWith(Ball& ball, float collisionTime) {
    if (!collidedLastFrame && abs(position.y - ball.getCenter().y) < ball.getRadius())
    {
        collidedLastFrame = true;
            return Vector2D{ 0, ball.getVelocity().y * -1 } / collisionTime;
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
