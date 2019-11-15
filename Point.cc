//Ethan Senor
//Cops and robbers project

//Data Structures 3700

#include "Point.h"
#include "fraction.h"


#include <iostream>

using namespace std;

Point::Point(Fraction fractionx,Fraction fractiony)
{
	x = fractionx;
	y = fractiony;
}


//the get funtions will be used when sorting.
Fraction Point::getx()
{
	return x;
}

Fraction Point::gety()
{
	return y;
}

Point Point::operator+(const Point &rhs)
{
	Fraction f1, f2;

	f1 = x + rhs.x;
	f2 = y + rhs.y;
	
	return Point(f1, f2);
}

Point Point::operator-(const Point &rhs)
{
	Fraction f1, f2;
	
	f1 = x - rhs.x;
	f2 = y - rhs.y;

	return Point(f1, f2);
}

//cross product
Fraction Point::operator*(const Point &rhs)
{
	Fraction f1;
	
	f1 = (x * rhs.y) - (y * rhs.x);

	return f1;
}

//Scales point
Point Point::operator*(Fraction &scaler)
{
	Fraction f1, f2;
	
	f1 = scaler * x;
	f2 = scaler * y;

	return Point(f1, f2);
}


//will read in (n/d, n/d) and throw out '(' ',' ')'.
istream &operator>>(istream &is, Point &p)
{
	Fraction xVal, yVal;
	//these are the values used when input that can be thrown out. 
	char lparenth, comma, rparenth;

	is >> lparenth >> xVal >> comma >> yVal >> rparenth;

	p = Point(xVal, yVal);
	
	return is;
}

//will output in the form (n/d, n/d)
ostream &operator<<(ostream &os, Point &p)
{
	os << '(' << p.x << ',' << p.y << ')';

	return os;
}
	











