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
   Rational(int,int=1);

   friend std::ostream& operator<<(std::ostream &, const Rational &);
   //does this one need to be a friend? 
   Rational & operator+=(const Rational &);
   friend Rational operator+(const Rational &, const Rational &);
   friend Rational operator-(const Rational &lhs);
   friend bool operator==(const Rational &lhs, const Rational &rhs);
   friend bool operator<(const Rational &lhs, const Rational &rhs);

public:
   Rational & operator-=(const Rational& rhs);
   Rational & operator*=(const Rational& rhs);
   Rational & operator/=(const Rational& rhs);
   Rational & operator++();        //prefix ++
   Rational operator++(int); //postfix ++
   Rational & operator--();        //prefix --
   Rational operator--(int); //postfix --


};

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
