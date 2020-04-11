#include "Score.h"


Score::Score()
{

}

Score::Score(Vector2D center)
{
	this->center = center;

}

void Score::draw(Interface& interface)
{

interface.drawScore(center);

}