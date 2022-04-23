#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>

//Rational.hpp
//CS 202 Sample Code
//Modified by Lisa Jacklin

// 3/2, 5/1, 10/2, 1008882/23428, 1/2*1/3==1/6
// class invariant:
// _denominator is always > 0

//now a template class
template <typename T> 
class Rational {
private:
   int _numerator;
   int _denominator;
   void reduce();  // only Rational member fcns can call this

public:
   // Rational() { _numerator=0; _denominator=1; }
   Rational<T>(int=0,int=1);
   //these operators don't need templates because rational<T> above serves as such.
   Rational<T>& operator-=(const Rational<T>& rhs);
   Rational<T>& operator*=(const Rational<T>& rhs);
   Rational<T>& operator/=(const Rational<T>& rhs);
   Rational<T>& operator +=(const Rational<T>& rhs); //added this missing operator
   Rational<T>& operator++();        //prefix ++
   Rational<T> operator++(int); //postfix ++
   Rational<T>& operator--();        //prefix --
   Rational<T> operator--(int); //postfix --

   template<typename U>
   friend std::ostream& operator<<(std::ostream & os, const Rational<U> & rhs);

   template<typename U>
   friend Rational<U> operator+(const Rational<U> & lhs, const Rational<U> & rhs);

   template<typename U>
   friend Rational<U> operator-(const Rational<U> &lhs);

   template<typename U>
   friend bool operator==(const Rational<U> &lhs, const Rational<U> &rhs);

   template<typename U>
   friend bool operator<(const Rational<U>&lhs, const Rational<U>&rhs);

};

template<typename T> 
std::ostream& operator<<(std::ostream& os, const Rational<T>& rhs) {
	return os;
}
template <typename T>
Rational<T>::Rational(int num, int den) : _numerator(num), _denominator(den) {
	reduce(); //only rational functions can call this! this reduces the fraction...
};
template<typename T>
Rational<T>& operator-=(const Rational <T>& lhs, const Rational<T>& rhs) {
	return lhs -= rhs;
}
template<typename T>
Rational<T>& operator*=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs *= rhs;
}
template<typename T>
Rational<T>& operator/(Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs /= rhs; //this doesn't seem right
}
template<typename T>
Rational<T>& operator++() {//prefix ++
	return *this += 1;
}
template<typename T>
Rational<T> operator++(int) {//postfix ++
	return *this += 2;
}
template<typename T>
Rational<T>& operator--(const Rational<T>& lhs) {//prefix --
	return *this -= 1;
}
template<typename T>
Rational<T> operator--(int) {//postfix --
	return *this -= 2;
}

template<typename T>
void Rational<T>::reduce() {
	T gcd = std::gcd(_numerator, _denominator); //should create a function
	//that takes the num and den and then gets a value...
	_numerator /= gcd;
	_denominator /= gcd;
	if (_denominator < 0) { //turns the answer to positive...
		_numerator *= -1;
		_denominator *= -1;
	}
}


template<typename U>
bool operator==(const Rational<U>& lhs, const Rational<U>& rhs) {
	return lhs == rhs; //need to check these...
 }
template<typename U>
bool operator<(const Rational<U>& lhs, const Rational<U>& rhs) {
	return lhs < rhs;
 }


template<typename U>
Rational<U> operator+(const Rational<U>& lhs, const Rational<U>& rhs) {
	return lhs + rhs; //double check this...might need a different way to do this
}
template<typename U>
Rational<U> operator-(const Rational<U>& lhs) {
	return { -lhs._numerator, lhs._denominator }; // returns the irrational num/den values
}



//and any operators I forgotthe first time round...
template <typename T>

#if 0
//these can be used as a base for the template versions
//rational opperators ...
Rational operator-(const Rational &lhs, const Rational &rhs);
Rational operator*(Rational lhs, const Rational &rhs);
Rational operator/(Rational lhs, const Rational &rhs);

//boolean operators
bool operator!=(const Rational &lhs, const Rational &rhs);
bool operator>(const Rational &lhs, const Rational &rhs);
bool operator<=(const Rational &lhs, const Rational &rhs);
bool operator>=(const Rational &lhs, const Rational &rhs);
#endif

#endif
