#include "Collectables.h"


Collectables::Collectables()
{

}


Collectables::Collectables(float radius, Vector2D center)
{
	this->radius = radius;
	this->center = center;
}

float Collectables::getRadius() const
{

	return radius;
}

Vector2D Collectables::getCenter() const
{
	return center;
}

void Collectables::draw(Interface& interface)
{

	interface.drawCollectable(center, radius);
}
