#pragma once
#include "element.h"

class MovingElement : Element
{
public:
	MovingElement();
	~MovingElement();

	void rotate(float alpha) {};
	void rotate(float alphaPerTimeUnit, float timeUnits) {};

	void move(float timeUnits = 1);
	void move(Point* direction, float timeUnits = 1);
	void move(Point* direction, float timeUnits, float speed);

	bool updatePosition(Point newPosition, bool teleport = false) { return false; };
	bool updateSpeed(float newSpeed) { return false; };
	bool updateDirection(Point* newDirection) { return false; };

	float getSpeed() { return m_speed; }

private:
	float m_speed;
};

