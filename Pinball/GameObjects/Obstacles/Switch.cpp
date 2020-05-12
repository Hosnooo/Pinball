#include "Switch.h"

Switch::Switch(Vector2D refpoint, float arclength, float angle): arclength(arclength), refpoint(refpoint), angle(angle){}

Vector2D Switch::collideWith(Ball& ball, float collisionTime)
{
  
    if (!collidedLastFrame && abs(position - ball.getCenter().x) < ball.getRadius())
    {
        if (passed == true)
        {
            collidedLastFrame = true;
            return Vector2D{ ball.getVelocity().x * -2 * cos(angle), ball.getVelocity().y * -2 * sin(angle) } / collisionTime;
        }
        passed = true;
    }
    else
    {
    }
}

void Switch::setpassed(bool passed)
{
    this->passed = passed;
}

void Switch::draw(Interface& interface)
{
	interface.drawSwitch(refpoint, arclength, angle);
};

