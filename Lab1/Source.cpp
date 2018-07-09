// Andrew Wilson - 16211406
// January 30, 2018
// CS201L Lab #2

#include <iostream>
#include <math.h>
using namespace std;


double callDistance(double X1, double Y1, double Z1, double X2, double Y2, double Z2)
{
	double deltaX, deltaY, deltaZ, distance;

	deltaX = X2 - X1;
	deltaY = Y2 - Y1;
	deltaZ = Z2 - Z1;

	distance = sqrt((pow((deltaX), 2)) + pow((deltaY), 2) + pow((deltaZ), 2));
	return distance;
}

int main()
{
	double X1, Y1, Z1, X2, Y2, Z2;

	cout << "3D DISTANCE CALCULATOR" << endl;
	cout << "Enter the x y and z coordinates for the first point, separated by spaces." << endl;
	cin >> X1 >> Y1 >> Z1;
	cout << "Now enter the x y and z coordinates for the second point, separated by spaces." << endl;
	cin >> X2 >> Y2 >> Z2;

	double distance = callDistance(X1, Y1, Z1, X2, Y2, Z2);

	cout << "The distance is " << distance << endl;
	system("pause");

	return 0;
}


