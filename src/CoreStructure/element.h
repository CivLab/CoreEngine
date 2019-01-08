#ifndef ELEMENT_H
#define ELEMENT_H

#include "../CoreGeometry/point.h"
#include "../WorldInterface/IElement.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <exception>

class Element : public IElement
{
public:

	Element() : m_isSolid(true) {}
	virtual ~Element() {}

//-----------------------------------------
//Virtual generic functions
	
	//display the shape on screen
	virtual void display() {};
	//returns true if the shape collides with another given shape
	virtual double distance(IElement &)		{ return -1; };
	virtual bool collideWith(IElement &)	{ return false; };
	virtual bool touch(IElement &)			{ return false; };

	virtual void updatePosition() {};
	virtual void updatePosition(const Point &vector, bool teleport);
	virtual void rotate(float alpha);

	virtual void updateDirection() {};
	virtual void updateDirection(const Point &newDirection) { m_position = newDirection; }
	virtual void updateDirection(double angle, bool rad = false);

	bool isSolid() { return m_isSolid; }

	Point getPosition() { return m_position; }
	Point getDirection() { return m_direction; }
	void setPosition(Point p) { m_position = p; }
	void setDirection(Point p) { m_direction = p; }
	int getID() { return m_ID; }
	
protected:
	Point m_direction;
	Point m_position;
	int m_ID; //Should we give them some ID so that we can recognise them in case of problem/bug ?
	bool m_isSolid; //Will it be treated for collisions ?
};
#endif