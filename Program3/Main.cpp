// Andrew Wilson - #16211406
// February 27, 2018
// CS201R - Gharibi
// Program #3 - UMKC Faculty & Students

// ALGORITHM
// 1) Initialize input stream
// 2) Declare two output streams for faculty and students
// 3) Read input once, print faculty information
// 4) Read input again, print student information
// 5) Close all streams

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Faculty.h"
#include "Student.h"

using namespace std;

int main()
{

	ifstream fin("input.txt");
	ofstream fout_f("FacultyOutput.txt", ios::app);
	ofstream fout_s("StudentOutput.txt", ios::app);
	Faculty fTemp;
	Student sTemp;

	fTemp.readWriteMembers(fin, fout_f);
	sTemp.readWriteMembers(fin, fout_s);
	
	fin.close();
	fout_f.close();
	fout_s.close();

	cout << "File writing complete." << endl;
	system("pause");

	return 0;

}