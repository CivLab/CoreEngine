#include "element.h"

void Element::updateDirection(double rad)
{
	double newX = m_position.X * cos(rad) - m_position.Y * sin(rad);
	double newY = m_position.Y * cos(rad) + m_position.X * sin(rad);
	updateDirection(Point(newX, newY));
}
