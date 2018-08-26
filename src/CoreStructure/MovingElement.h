#pragma once
#include "../CoreGeometry/element.h"

class MovingElement : Element
{
public:
	MovingElement();
	~MovingElement();

	bool updatePosition(float timeLapse);
	bool updateSpeed(Point* newSpeed);
	bool updateDirection(Point* newDirection);

private:
	float m_speed;
};

