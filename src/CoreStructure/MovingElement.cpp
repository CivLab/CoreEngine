#include "MovingElement.h"

MovingElement::MovingElement()
{
}


MovingElement::~MovingElement()
{
}

void MovingElement::move(float timeUnits)
{
	Point* pDirection = &getDirection();
	float speed = getSpeed();
	move(pDirection, timeUnits, speed);
}

void MovingElement::move(Point * direction, float timeUnits)
{
	float speed = getSpeed();
	move(direction, timeUnits, speed);
}

void MovingElement::move(Point * direction, float timeUnits, float speed)
{
	float distance = timeUnits * speed;
	updatePosition(*direction*distance);
}
