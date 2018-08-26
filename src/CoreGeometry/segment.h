#ifndef ELEMENT_H
#define ELEMENT_H

#include "element.h"

class Segment : public Element
{

	//Note : The class will regroup both Segment and Vectors... See if it has to be changed later.
public:
	Segment();
	Segment(Point A, Point B);

	std::vector<Point> getPoints() { return m_Points; }

	double length();

	//Assert that the Segment is correctly living (ie has two points)
	bool hasTwoPoints();

	//returns True if the point is on the segment
	bool isOnSegment(Point* pPoint);
	//Returns the shortest distance from a given point to the segment
	Point getClosestOnSegment(Point* pPoint);
	double distance(Point* pPoint);

	//Returns a pointer to the intersection with another segment (nullptr if the segments do not intersect)
	Point intersectWith(Segment* pSegment);
	Point projection(Point* pPoint);

	//Get normal vector
	Point getNormal(Element*) { return getNormal(); };
	Point getNormal();
	//Get tangent Vector
	Point getTangent();

	//Update
	void update(Point N) {};

protected:
	//should contain 2 points
	std::vector<Point> m_Points;
};
#endif // !ELEMENT_H
