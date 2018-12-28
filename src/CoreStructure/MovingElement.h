#pragma once
#include "element.h"

class MovingElement : public Element
{
public:
	MovingElement();
	~MovingElement();

	void move(float timeUnits = 1);
	void move(Point* direction, float timeUnits = 1);
	void move(Point* direction, float timeUnits, float speed);

	bool updateSpeed(float newSpeed) { return false; };

	float getSpeed() { return m_speed; }

private:
	float m_speed;
};

