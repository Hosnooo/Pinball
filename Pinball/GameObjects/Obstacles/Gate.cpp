#include "Gate.h"

Gate::Gate(Vector2D refpoint, float arclength, float angle): arclength(arclength), refpoint(refpoint), angle(angle){}

Vector2D Gate::collideWith(Ball& ball, float collisionTime)
{
  
    if (!collidedLastFrame && abs(refpoint.y - ball.getCenter().y) < ball.getRadius()
        && (abs(refpoint.x - ball.getCenter().x) < ball.getRadius() || abs(refpoint.x + ARC_LENGTH - ball.getCenter().x) < ball.getRadius()))
    {
           collidedLastFrame = true;
            return Vector2D{ ball.getVelocity().x, ball.getVelocity().y * -1 } / collisionTime;
       
       
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}



void Gate::draw(Interface& interface)
{
    interface.drawGate(refpoint, arclength, angle);

};

