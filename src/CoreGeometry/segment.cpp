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
	//Will return -1 if the Segment has less than two points...
	int d = hasTwoPoints() ? m_Points[0].distance(&m_Points[1]) : -1;
	return d;
}

Point Segment::intersectWith(Segment* pSegment)
{
	//Suppose that the first Segment is AB, the second CD, we look for the intersection E such as 
	//E = A + alpha (B-A) = C + beta (D-C)
	//All lines ^(B-A) gives A^(B-A) = C^(B-A) + beta (D-C)^(B-A) and gives beta
	if (!hasTwoPoints() || pSegment->hasTwoPoints())
	{
		//TODO : Add error messages somewhere !
		return DUMMY;
	}

	Point
		A = m_Points[0],
		BminA = m_Points[1] - A,
		C = pSegment->getPoints()[0],
		DminC = pSegment->getPoints()[1] - C;

	double beta_num = ((A - C).determinant(&BminA));
	double beta_den = (DminC.determinant(&BminA));

	if (beta_den != 0)
	{
		double beta = beta_num / beta_den;
		if (beta >= 0 && beta <= 1)
			return (C + DminC*beta);
	}

	return DUMMY;
}

Point Segment::getNormal()
{
	Point U(-(m_Points[0].Y - m_Points[1].Y), m_Points[0].X - m_Points[1].X);
	return U / U.normL2();;
}

Point Segment::getTangent()
{
	Point T = hasTwoPoints() ? m_Points[1] - m_Points[0] : Point();
	return (T == Point() ? Point() : T / T.normL2());
}

Point Segment::projection(Point* pPoint)
{
	//If we want to calculate the projection D of C on AB
	//We write the following equations :
	// AB.CD = 0 and D = A + alpha * (B-A)
	//If alpha is in [0;1] then D is indeed on the segment, else it falls outside on the line.
	if (length() > 0)
	{
		Point T = m_Points[1] - m_Points[0];
		double L = length()*length();
		double alpha = (T.X*(pPoint->X - m_Points[0].X) + T.Y*(pPoint->Y - m_Points[0].Y)) / L;
		if (alpha >= 0 && alpha <= 1)
			return m_Points[0] + T*alpha;
	}
	return DUMMY;
}

bool Segment::isOnSegment(Point* pPoint)
{
	//The point is on the segment if and only if
	//its projection on the segment is itself
	return *pPoint == projection(pPoint);
}

Point Segment::getClosestOnSegment(Point* pPoint)
{
	Point P = projection(pPoint);
	if (P == DUMMY && hasTwoPoints()) //if the segment exists and the projection is outside of the segment
		return ((pPoint->distance(&m_Points[0]) <= pPoint->distance(&m_Points[0])) ? m_Points[0] : m_Points[1]);
	else
		return P;
}


double Segment::distance(Point* pPoint)
{
	//Either the distance between the point and its projection on the segment if it exists
	//Or the distance to the closest point of the segment if it doesn't
	Point P = projection(pPoint);
	if (P == DUMMY)
		return std::min(pPoint->distance(&m_Points[0]), pPoint->distance(&m_Points[0]));
	else
		return pPoint->distance(&P);
}