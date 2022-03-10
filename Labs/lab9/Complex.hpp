//complex.cpp
//Lisa Jacklin
// CS 202
// 3/10/2022
//

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

//1. complex number class
class Complex {
public:
	//stream insertion operator
	friend std::ostream& operator << (std::ostream&, Complex c);
	
	//constructor with two doubles, the imaginary portion set to zero
	Complex(double, double = 0);

	// operator +=
	Complex& operator+=(const Complex& c);
private:
	//gives us that there are real and imaginary portions
	double _real;
	double _imaginary;

};
//operator +
Complex operator+(const Complex&, const Complex&);

#endif