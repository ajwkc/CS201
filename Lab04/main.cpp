// Andrew Wilson #16211406
// March 6, 2018
// CS201L Midterm #1

#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	cout << "file connections complete";

	while (!fin.eof())
	{
		int r, c;
		fin >> r >> c;
		cout << "r is " << r << " and c is " << c << endl;
		Matrix m1(r, c), m2(r, c);
		fin >> m1 >> m2;

		Matrix m3 = m1 - m2;
		fout << m3;
	}

	cout << "finished";
	system("pause");

	return 0;
}