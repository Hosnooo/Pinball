#include "Switch.h"

Switch::Switch(Vector2D refpoint, float length, float angle) : length(length), refpoint(refpoint), angle(angle){}

Vector2D Switch::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && abs(refpoint.y - ball.getCenter().y) < ball.getRadius())
    {
                  collidedLastFrame = true;
            return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
    }
}



void Switch::draw(Interface& interface) 
{
    interface.drawSwitch(refpoint, length, angle);

}