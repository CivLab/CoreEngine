#ifndef SEGMENT_H
#define SEGMENT_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <exception>

#include "point.h"

class Segment
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
	bool isOnSegment(Point &pPoint);
	//Returns the shortest distance from a given point to the segment
	Point getClosestOnSegment(Point &pPoint);
	double distance(Point &pPoint);

	//returns true if a point was found with the point
	std::pair<bool, Point> intersectWith(Segment &pSegment);
	std::pair<bool, Point> projection(const Point &pPoint);

	//Get normal vector
	Point getNormal();
	//Get tangent Vector
	Point getTangent();

	//Update
	void update(Point N) {};

protected:
	//should contain 2 points
	std::vector<Point> m_Points;
	Point m_direction;
	Point m_position;
	int m_ID; //Should we give them some ID so that we can recognise them in case of problem/bug ?
};
#endif // !ELEMENT_H
