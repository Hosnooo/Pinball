#include "SpeedBoosters.h"


SpeedBoosters::SpeedBoosters()
{

}


SpeedBoosters::SpeedBoosters(float radius, Vector2D center)
{
	this->radius = radius;
	this->center = center;
}

float SpeedBoosters::getRadius() const
{

	return radius;
}

Vector2D SpeedBoosters::getCenter() const
{
	return center;
}

Vector2D SpeedBoosters::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && sqrt(pow(center.x - ball.getCenter().x, 2) + pow(center.y - ball.getCenter().y, 2)) <= ball.getRadius() + MULTIPLIERS_RADIUS)
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x , ball.getVelocity().y } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}


void SpeedBoosters::draw(Interface& interface) 
{

	interface.drawSpeedBooster(center, radius);
}

