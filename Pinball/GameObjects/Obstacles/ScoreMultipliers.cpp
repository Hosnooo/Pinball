#include "ScoreMultipliers.h"

ScoreMultipliers::ScoreMultipliers()
{
}


ScoreMultipliers::ScoreMultipliers(float radius, Vector2D center)
{
	this->radius = radius;
	this->center = center;
}

float ScoreMultipliers::getRadius() const
{

	return radius;
}

Vector2D ScoreMultipliers::getCenter() const
{
	return center;
}

void ScoreMultipliers::draw(Interface& interface)
{

	interface.drawScoreMultiplier(center, radius);
}

Vector2D ScoreMultipliers::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && sqrt(pow(center.x - ball.getCenter().x,2)+ pow(center.y - ball.getCenter().y,2)) <= ball.getRadius() + MULTIPLIERS_RADIUS)
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }         
}