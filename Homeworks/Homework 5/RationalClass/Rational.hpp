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

//note: Rational<T>& Rational<T>:: is used because we defined the operators with Rational<T> originally..

template<typename T> 
std::ostream& operator<<(std::ostream& os, const Rational<T>& rhs) {
	return os;
}
template <typename T>
Rational<T>::Rational(int num, int den) : _numerator(num), _denominator(den) {
	reduce(); //only rational functions can call this! this reduces the fraction...
};
template<typename T>
Rational<T>& Rational<T>::operator-= (const Rational<T>& rhs) {
	*this = *this - rhs; //adjusted to match class and correctly do subtraction.
	return &this;
}
template<typename T>
Rational<T>& Rational<T>::operator*=( const Rational<T>& rhs) {
	_numerator *= rhs._numerator;
	_denominator *= rhs._denominator;
	reduce();
	return *this;
}
//These are a few I missed! for rhs..
template <typename T>
Rational<T>& Rational<T>::operator+= (const Rational<T>& rhs) {
	_numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
	_denominator *= rhs._denominator;
	reduce();
	return *this;
}
template <typename T>
Rational<T>& Rational<T>:: operator/= (const Rational<T>& rhs) {
	*this *= {rhs._denominator, rhs._numerator}; //now *this is a fraction that an be reduced
	reduce();
	return *this;
}


template<typename T>
Rational<T>& Rational<T>::operator++() {//prefix ++
	return *this += 1;
}
template<typename T>
Rational<T> Rational<T>::operator++(int) {//postfix ++
	auto copy{ *this };
	++(*this);
	return copy;
}
template<typename T>
Rational<T>& Rational<T>::operator--() {//prefix --
	return *this -= 1;
}
template<typename T>
Rational<T> Rational<T>::operator--(int) {//postfix --
	auto copy{ *this };
	--(*this);
	return copy;
}

//function template
template<typename T>
void Rational<T>::reduce() {
	T gcd = gcd(_numerator, _denominator); //should create a function
	//that takes the num and den and then gets a value...
	_numerator /= gcd;
	_denominator /= gcd;
	if (_denominator < 0) { //turns the answer to positive...
		_numerator *= -1;
		_denominator *= -1;
	}
}

//boolean operators
template<typename T>
bool operator==(const Rational<T>& lhs, const Rational<T>& rhs) {
	//return lhs == rhs; //need to check these...
	//adjusting this to make sure nums are equal and den are equal
	return lhs._numerator == rhs._numerator && lhs._denominator == rhs._denominator;
 }
template<typename T>
bool operator<(const Rational<T>& lhs, const Rational<T>& rhs) {
	//return lhs < rhs;
	//this sets the value less than the other when cross multiplied
	return lhs._numerator * rhs._denominator < rhs._numerator* lhs._denominator;
 }
//missed bool operators:
template<typename T>
bool operator != (const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(rhs == lhs);
}
template <typename T>
bool operator > (const Rational<T>& lhs, const Rational<T> &rhs) {
	return rhs < lhs;
}
template <typename T>
bool operator <= (const Rational<T>& lhs, const Rational <T>& rhs) {
	return !(rhs > lhs);
}
template <typename T>
bool operator >= (const Rational<T>& lhs, const Rational <T>& rhs) {
	return !(rhs < lhs);
}


template<typename U>
Rational<U> operator+(const Rational<U>& lhs, const Rational<U>& rhs) {
	return lhs + rhs; //double check this...might need a different way to do this
}
template<typename U>
Rational<U> operator-(const Rational<U>& lhs) {
	return { -lhs._numerator, lhs._denominator }; // returns the irrational num/den values
}
//other missing templates
template <typename U>
Rational<U> operator-(const Rational<U> &lhs, const Rational<U> &rhs) { 
	return lhs + -rhs;
}
template <typename U>
Rational<U> operator*(Rational<U> lhs, const Rational<U>& rhs) {
	return lhs *= rhs;
}
template <typename U>
Rational<U> operator/ (Rational <U> lhs, const Rational<U>& rhs) {
	return lhs /= rhs;
}

#if 0
//these can be used as a base for the template versions
// a bunch of these are from the ones i think I left out...
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
