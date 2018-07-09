#include "Matrix.h"

Matrix::Matrix(int r, int c)
	: nRows(r), nCols(c) {}

void Matrix::set(int r, int c, int v)
{
	grid[r][c] = v;
}

int Matrix::get(int r, int c)
{
	return grid[r][c];
}

const Matrix operator -(const Matrix& m1, const Matrix& m2)
{
	int rows = m1.nRows;
	int cols = m2.nCols;
	Matrix m3(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m3.grid[i][j] = (m1.grid[i][j] - m2.grid[i][j]);
		}
	}
	return m3;
}

istream& operator>>(istream& input, Matrix m)
{
	
	for (int i = 0; i < m.nRows; i++)
	{
		for (int j = 0; j < m.nCols; j++)
		{
			input >> m.grid[i][j];
		}
		
	}
	return input;
}

ostream& operator<<(ostream& output, const Matrix m)
{

	for (int i = 0; i < m.nRows; i++)
	{
		for (int j = 0; j < m.nCols; j++)
		{
			output << m.grid[i][j] << '\t';
		}
		output << endl;
	}
	return output;
}