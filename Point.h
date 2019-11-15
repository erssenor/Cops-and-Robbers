//Ethan Senor
//Cops and robbers project

//Data Structures 3700
#ifndef _POINT_H
#define _POINT_H

#include "fraction.h"

using namespace std;
class Point 
{
	public:
		
		Point(Fraction x = Fraction(), Fraction y = Fraction());
		~Point (void) { };
		
		//The get functions will be used in the sort		
		Fraction getx();
		Fraction gety();
		Point operator+(const Point &rhs);
		Point operator-(const Point &rhs);
		Point operator*(Fraction &scaler);
		Fraction operator*(const Point &rhs);

		friend istream &operator>>(istream &, Point &);
		friend ostream &operator<<(ostream &, Point &);

	private:
		Fraction x, y;
};






#endif
