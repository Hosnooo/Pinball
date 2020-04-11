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

void SpeedBoosters::draw(Interface& interface) 
{

	interface.drawSpeedBooster(center, radius);
}

