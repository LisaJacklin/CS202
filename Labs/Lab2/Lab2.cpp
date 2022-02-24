//L2.cpp
//Lisa Jaclin
//CS 202
//2/10/2022

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//this file connects the Labtwo class to L2.cpp
#include "Lab2.hpp"

//Now, functions from steps 3 through 6
//notice that fcn stands for function

//NOTE: these functions would not work correctly when placed in Labtwo.cpp
//test around and see why....

//passing an object by value
void fcn_by_value(Labtwo x1) { cout << "start of fcn_by_value" << endl; }

//passing an object by reference
void fcn_by_reference(Labtwo& x1) { cout << "start of fcn_by_reference" << endl; }

//passing a constant reference
void fcn_by_const_reference(const Labtwo& x1) { cout << "start of fcn_by_const_reference" << endl; }

//lastly, returning an object by value.
Labtwo fcn_return_by_value()
{
	Labtwo b; // local variable
	return b;
}

int main() {
	cout << "start of main" << endl;

	Labtwo a; //local class object
	Labtwo b = a; 	//Copy of another class object

	//now to use the functions that were created in Labtwo.cpp
	//steps 3 thorugh 6
	fcn_by_value(a); //passes the value of a
	fcn_by_reference(a);
	fcn_by_const_reference(a);
	a = fcn_return_by_value();
	//now for step 7: creating a vector of class objects...
	cout << "vector being built" << endl;
	vector<Labtwo> v(5);
	v[2] = a;

	cout << "end of main" << endl;
}

//don't forget to check that the destructor comes after the end of main!