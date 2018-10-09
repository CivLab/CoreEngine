#include "segment.h"
//------------------------------------------------
//segment Related functions

Segment::Segment(Point A, Point B)
{
	m_Points.push_back(A);
	m_Points.push_back(B);

	m_position = (A + B)/2.;

	m_direction = getNormal();
}

bool Segment::hasTwoPoints()
{
	return m_Points.size() == 2;
}

double Segment::length()
{
	if (!hasTwoPoints())
	{
		throw std::length_error("Segment has less than two points.");
	}

	return m_Points[0].distance(m_Points[1]);
}

std::pair<bool,Point> Segment::intersectWith(Segment &pSegment)
{
	//Suppose that the first Segment is AB, the second CD, we look for the intersection E such as 
	//E = A + alpha (B-A) = C + beta (D-C)
	//All lines ^(B-A) gives A^(B-A) = C^(B-A) + beta (D-C)^(B-A) and gives beta
	bool intersect = false;
	Point intersection;

	if (!hasTwoPoints() || pSegment.hasTwoPoints())
	{
		throw std::length_error("Segment has less than two points.");
	}

	Point
		A = m_Points[0],
		BminA = m_Points[1] - A,
		C = pSegment.getPoints()[0],
		DminC = pSegment.getPoints()[1] - C;

	double beta_num = ((A - C).determinant(BminA));
	double beta_den = (DminC.determinant(BminA));

	if (beta_den != 0)
	{
		double beta = beta_num / beta_den;
		if (beta >= 0 && beta <= 1)
		{
			intersect = true;
			intersection = Point(C + DminC*beta);
		}
	}
	return(std::make_pair(intersect, intersection));
}

Point Segment::getNormal()
{
	if (!hasTwoPoints()) //should not happen
	{
		throw std::length_error("Segment has less than two points.");
	}

	if (length() <= 0)
	{
		return Point(0, 0);
	}

	Point U(-(m_Points[0].Y - m_Points[1].Y), m_Points[0].X - m_Points[1].X);
	return U / U.normL2();;
}

Point Segment::getTangent()
{
	if (!hasTwoPoints()) //should not happen
	{
		throw std::length_error("Segment has less than two points.");
	}

	if (length() <= 0)
	{
		return Point(0, 0);
	}

	Point T = m_Points[1] - m_Points[0];
	return (T / T.normL2());
}

std::pair<bool, Point> Segment::projection(const Point &pPoint)
{
	//If we want to calculate the projection D of C on AB
	//We write the following equations :
	// AB.CD = 0 and D = A + alpha * (B-A)
	//If alpha is in [0;1] then D is indeed on the segment, else it falls outside on the line.
	bool projectionExists = false;
	Point projection;
	if (length() > 0)
	{
		Point T = m_Points[1] - m_Points[0];
		double L = length()*length();
		double alpha = (T.X*(pPoint.X - m_Points[0].X) + T.Y*(pPoint.Y - m_Points[0].Y)) / L;
		if (alpha >= 0 && alpha <= 1)
		{
			projectionExists = true;
			projection = m_Points[0] + T*alpha;
		}
	}

	return (std::make_pair(projectionExists, projection));
}

bool Segment::isOnSegment(Point &pPoint)
{
	//The point is on the segment if and only if
	//its projection is on the segment is itself
	auto projectionCalc = projection(pPoint);
	return (projectionCalc.first && pPoint == projectionCalc.second);
}

Point Segment::getClosestOnSegment(Point &pPoint)
{
	auto projectionCalc = projection(pPoint);
	if (projectionCalc.first == false && hasTwoPoints()) //if the segment exists and the projection is outside of the segment
		return ((pPoint.distance(m_Points[0]) <= pPoint.distance(m_Points[0])) ? m_Points[0] : m_Points[1]);
	else
		return projectionCalc.second;
}


double Segment::distance(Point &pPoint)
{
	//Either the distance between the point and its projection on the segment if it exists
	//Or the distance to the closest point of the segment if it doesn't
	auto projectionCalc = projection(pPoint);
	if (projectionCalc.first == false)
		return std::min(pPoint.distance(m_Points[0]), pPoint.distance(m_Points[1]));
	else
		return pPoint.distance(projectionCalc.second);
}