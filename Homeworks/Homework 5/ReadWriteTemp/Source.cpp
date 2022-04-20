//Source.cpp
// Lisa Jacklin
// CS 202 Homework 5
// Read Write Template
// 4/16/2022
//

#include <iostream>
using std::cout;
using std::endl;

using std::ofstream;
using std::ifstream;

int main() {
	ofstream ofile("numbers.dat");
	double d = 13.3;
	myWrite(ofile, d);
	int x = 5;
	myWrite(ofile, x);

	ifstream ifile("numbers.dat");
	double readd;
	int readx;

	myRead(ifile, readd);
	myRead(ifile, readx);

}

