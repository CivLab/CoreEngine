#ifndef POINT_H
#define POINT_H

#include <cmath>
#include<stdexcept>

#define DUMMY Point(-1,-1)
constexpr auto PI = 3.14159265;
const double epsilon = 0.000001;

class Point {
public:
	double X;
	double Y;

	//Constructors
	Point();
	Point(double , double);
	~Point() {}
	
	Point normalize();
	double determinant(const Point &pPoint);
	double normL2();

	void translate(double x, double y);
	void translate(const Point &p);
	void rotate(float angle, bool rad = false);

	double distance();
	double distance(const Point &);

	Point operator-(const Point &);
	Point operator+(const Point &);
	Point operator*(double);
	double operator*(const Point &);
	Point operator/(double);
	bool operator==(const Point &);
};

#endif
