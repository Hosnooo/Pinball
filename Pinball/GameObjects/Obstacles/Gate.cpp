#include "Gate.h"

Gate::Gate(Vector2D refpoint, float arclength, float angle): arclength(arclength), refpoint(refpoint), angle(angle){}

Vector2D Gate::collideWith(Ball& ball, float collisionTime)
{
  
    if (!collidedLastFrame && abs(refpoint.y - ball.getCenter().y) < ball.getRadius())
    {
        if (passed == true)
        {
            collidedLastFrame = true;
            return Vector2D{ ball.getVelocity().x * -2 * cos(angle), ball.getVelocity().y * -2 * sin(angle) } / collisionTime;
        }
        setpassed(true);
    }
    else
    {
    }
}

void Gate::setpassed(bool passed)
{
    this->passed = passed;
}

void Gate::draw(Interface& interface)
{
    interface.drawGate(refpoint, arclength, angle);

};

