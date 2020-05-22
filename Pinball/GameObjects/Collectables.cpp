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

void Collectables::ChangeColor(Ball & ball, Interface & interface)
    {
        if (!collidedLastFrame && sqrt(pow(getCenter().x - ball.getCenter().x, 2) + pow(getCenter().y - ball.getCenter().y, 2)) <= ball.getRadius() + MULTIPLIERS_RADIUS)
        {
            collidedLastFrame = true;
            interface.drawCollectable(center, radius, sf::Color::Yellow);
        }
        else
        {
            collidedLastFrame = false;
        }
 }

void Collectables::setCollidedLastFrame(bool coll)
{
    collidedLastFrame = coll;
}

bool Collectables::getCollidedLastFrame()
{
    return collidedLastFrame;
}

void Collectables::draw(Interface& interface)
{

	interface.drawCollectable(center, radius, sf::Color::Cyan);
}
