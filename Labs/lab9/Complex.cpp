//complex.cpp
//Lisa Jacklin
// CS 202
// 3/10/2022
//

#include <iostream>
#include "Complex.hpp"

//since complex(double,double) is already defined in class, we must take 
//one of the constructors out.
Complex::Complex(double r, double i) : _real(r), _imaginary(i) {}

//explaining and expanding the operators
Complex & Complex::operator+=(const Complex& c) {
	_real += c._real;
	_imaginary += c._imaginary;
	return *this;
}

Complex operator+(const Complex& x, const Complex& c) {
	Complex temp(x);
	temp += c;
	return temp;
}

std::ostream& operator<<(std::ostream& os, Complex c) {
	return os << c._real << " + " << c._imaginary << "i";
}
