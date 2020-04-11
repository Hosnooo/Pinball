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
	return Vector2D{ 0,0 };
}