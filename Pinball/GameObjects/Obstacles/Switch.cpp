#include "Switch.h"

Switch::Switch(Vector2D refpoint, float length, float angle) : length(length), refpoint(refpoint), angle(angle){}

Vector2D Switch::collideWith(Ball& ball, float collisionTime)
{
    
    if (!collidedLastFrame && abs(refpoint.y - ball.getCenter().y) < ball.getRadius() 
        && (abs(refpoint.x - ball.getCenter().x) < ball.getRadius() || abs(refpoint.x + GATE_LENGTH - ball.getCenter().x) < ball.getRadius()))
    {
        if (passed == true)
        {
            collidedLastFrame = true;
            return Vector2D{ ball.getVelocity().x, ball.getVelocity().y * -1 } / collisionTime;
        }

        else
        {
            setpassed(true);
        }
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
 }

void Switch::setpassed(bool passed)
{
    this->passed = passed;
}




void Switch::draw(Interface& interface) 
{
    interface.drawSwitch(refpoint, length, angle);

}