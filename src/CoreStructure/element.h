#ifndef ELEMENT_H
#define ELEMENT_H

#include "../CoreGeometry/point.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <exception>

class Element {
public:

	Element() {}
	virtual ~Element() {}

//-----------------------------------------
//Virtual generic functions
	
	//display the shape on screen
	virtual void display() {};
	//returns true if the shape collides with another given shape
	virtual double distance(Element &)		{ return -1; };
	virtual bool collideWith(Element &)	{ return false; };
	virtual bool touch(Element &)			{ return false; };

	virtual void updatePosition() {};
	virtual void updatePosition(const Point &vector) { m_position = m_position + vector; }

	virtual void updateDirection() {};
	virtual void updateDirection(const Point &newDirection) { m_position = newDirection; }
	virtual void updateDirection(double rad);

	Point getPosition() { return m_position; }
	Point getDirection() { return m_direction; }
	int getID() { return m_ID; }
	
protected:
	Point m_direction;
	Point m_position;
	int m_ID; //Should we give them some ID so that we can recognise them in case of problem/bug ?
};
#endif