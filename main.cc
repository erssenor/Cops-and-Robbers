#include "Point.h"
#include "fraction.h"
#include <iostream>

using namespace std;


void findHull(Point p[], int k, Point hull[], int &numhull);
void sort(Point p[], int k);
bool turnsLeft(Point a, Point b, Point c);
bool turnsRight(Point a, Point b, Point c);
bool insideHull(Point P, Point Hull[], int k);

const int SIZE = 100;

int main() 
{
	Point pointsCop[SIZE], pointsRob[SIZE], pointsPeop[1000];
	Point hullCop[SIZE], hullRob[SIZE];
	int numhullCop, numhullRob;

	//c = cops, r = robbers, o = people
	int c, r, o;
	int safe = 0, robbed = 0, danger = 0;

	


	//Step 1 input values for cops, robbers and people. 
	cout << "Enter how many cops, robbers and people you want." << endl;
	cin >> c >> r >> o;

	
	//the if/else statement protects from invalid entries
	if(c < 3 || c > 100)
		cout << "Invalid input for cops" << endl;
	else if(r < 3 || r > 100)
		cout << "Invalid input for robbers" << endl;
	else if(o < 1)
		cout << "Invalid input for people" << endl;
	else
	{
		

	//Step 2 get points for each
	cout << "Enter the positions for each thing." << endl; 
	for(int i = 0; i < c; i++) //get individual points for the cops
	{
		cin >> pointsCop[i];
	}
	
	for(int i = 0; i < r; i++)//robbers
	{
		cin >> pointsRob[i];
	}
	
	for(int i = 0; i < o; i++)//people
	{
		cin >> pointsPeop[i];
	}

	
	//step 3/4 sort + find hull. 
	//get convex hull for each array of points
	numhullCop = 0;	
	findHull(pointsCop, c, hullCop, numhullCop);
	numhullRob = 0;
	findHull(pointsRob, r, hullRob, numhullRob);

	//step 5 find if its in a hull
	for(int i = 0; i < o; i++)
	{
		if(insideHull(pointsPeop[i], hullCop, numhullCop)==true)
			safe++;
		else if(insideHull(pointsPeop[i], hullRob, numhullRob) 									== true)
			robbed++;
		else
			danger++;
	}

	cout << "Safe: " << safe << endl;
	cout << "Robbed: " << robbed << endl;
	cout << "Danger: " << danger << endl;

	}
	return 0;
}

//step 3 find convex hull
void findHull(Point p[]/* p is the original array*/, int k, Point hull[] 			 , int &numhull)
{
	Point lower[SIZE], upper[SIZE];
	sort(p, k);
	int t, u;

	//this seciton sorts bottom portion of hull. 
	lower[0] = p[0];
	t = 0;
	for(int i = 1; i <= (k-1); i++)
	{
		while(t > 0 && turnsLeft(lower[t-1], lower[t], p[i]) == 			false)
		{
			t -= 1;
		}
		
		t += 1;
		lower[t] = p[i];
	}
	
	//this section sorts top part of hull
	upper[0] = p[k-1];
	u = 0;
	for(int i = (k-2); i >= 0; i--)
	{
		while(u > 0 && turnsLeft(upper[u-1], upper[u], p[i]) == 			false)
		{
			u -= 1;
		}
		u += 1;
		upper[u] = p[i];
	}

	
	for(int i = 0; i < t; i++)
		hull[numhull++] = lower[i];
	for(int i = 0; i < u; i++)
		hull[numhull++] = upper[i];
}

	
	
//step 4 sort array
//sort works correctly!
void sort(Point p[], int k /*k represents total number of items in 					array*/)
{
	Point temp;

	for(int start = 0; start < (k-1); start++)
	{
		for(int i = (start + 1); i < k; i++)
		{
			//sorts by x value. if tie sorts by y value. 
			if(p[i].getx() < p[start].getx() || (p[i].getx() 				   == p[start].getx() && p[i].gety() < 				   p[start].gety()))
			{
				temp = p[start];
				p[start] = p[i];
				p[i] = temp;
			}
		}
	}
}

//function works
bool turnsLeft(Point a, Point b, Point c)
{
	return(b-a)*(c-a) > Fraction(0);
}

bool turnsRight(Point a, Point b, Point c)
{
	return(b-a)*(c-a) < Fraction(0);
}


//step 5 determine if point is inside hull
bool insideHull(Point P, Point Hull[], int k)
{
	int j;
	
	for(int i = 0; i <= k-1; i++)
	{
		j = (i + 1) % k;
		
		if(turnsRight(P, Hull[i], Hull[j]) == true)
			return false;
	}
	
	return true;
}	









