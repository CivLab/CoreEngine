#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"
#include <vector>
#include <algorithm>

class Element {
public:

	Element() {}
	virtual ~Element() {}

//-----------------------------------------
//Virtual generic functions
	
	//display the shape on screen
	virtual void display() {};
	//returns true if the shape collides with another given shape
	virtual int distance(Element *)		{ return -1; };
	virtual bool collideWith(Element *)	{ return false; };
	virtual bool touch(Element *)			{ return false; };

	Point getPosition() { return m_position; };
	Point getDirection() { return m_direction; }
	
protected:
	Point m_direction;
	Point m_position;
	int m_ID; //Should we give them some ID so that we can recognise them in case of problem/bug ?
};
#endif