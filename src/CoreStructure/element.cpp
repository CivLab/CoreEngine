#include "element.h"

void Element::updateDirection(double angle, bool rad)
{
	if (!rad)
	{
		angle = angle * PI / 180.f;
	}
	double newX = m_position.X * cos(angle) - m_position.Y * sin(angle);
	double newY = m_position.Y * cos(angle) + m_position.X * sin(angle);
	updateDirection(Point(newX, newY));
}

void Element::rotate(float alpha)
{
	m_direction.rotate(alpha);
}

void Element::updatePosition(const Point &vector, bool teleport)
{
	if (teleport)
	{
		m_position = vector;
	}
	else
	{
		m_position = m_position + vector;
	}
}
