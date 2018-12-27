#include "point.h"
//default constructor returns O
Point::Point() :X(0), Y(0) {};

Point::Point(double x, double y) :X(x), Y(y) {};

double Point::distance(const Point &pPoint)
{
	double dX = X - pPoint.X;
	double dY = Y - pPoint.Y;
	return std::sqrt(dX*dX + dY*dY);
}

double Point::distance()
{
	return distance(Point());
}

void Point::translate(double x, double y)
{
	X += x;
	Y += y;
}

void Point::translate(const Point &p)
{
	translate(p.X, p.Y);
}

Point Point::normalize()
{
	return *this / normL2();
}

double Point::determinant(const Point &pPoint)
{
	// Return Point ^ pPoint*
	return (X*pPoint.Y - Y*pPoint.X);
}

//-----------------------------------
//Operator Overloads
Point Point::operator-(const Point &p) {
	return Point(X - p.X, Y - p.Y);
}

Point Point::operator+(const Point &p)
{
	return Point(X + p.X, Y + p.Y);
}

Point Point::operator*(double k) 
{
	return Point(k*X, k*Y);
}

double Point::operator*(const Point &p) 
{
	return (X*p.X + Y*p.Y);
}

bool Point::operator==(const Point &p)
{
	return (std::abs(X - p.X) < epsilon && std::abs(Y - p.Y) < epsilon);
}

double Point::normL2() 
{
	return distance(Point(0, 0));
}

Point Point::operator/(double k) 
{
	if (k == 0)
	{
		throw std::logic_error("division by 0 not possible");
	}
	return operator*(1 / k);
}

void Point::rotate(float angle)
{
	float newX = X * cos(angle) - Y * sin(angle);
	float newY = X * sin(angle) + Y * cos(angle);
	X = newX;
	Y = newY;
}