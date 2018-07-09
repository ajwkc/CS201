#include <iostream>
#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix
{
private:
	
public:
	int nRows, nCols;
	int grid[50][50];

	Matrix(int r, int c);
	void set(int r, int c, int v);
	int get(int r, int c);
	friend const Matrix operator -(const Matrix& m1, const Matrix& m2);
	friend istream& operator>>(istream& input, const Matrix m);
	friend ostream& operator<<(ostream& output, const Matrix m);

};

#endif