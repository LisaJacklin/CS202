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
   Rational<T>(int,int=1);
   //these operators don't need templates because rational<T> above serves as such.
   Rational<T>& operator-=(const Rational& rhs);
   Rational<T>& operator*=(const Rational& rhs);
   Rational<T>& operator/=(const Rational& rhs);
   Rational<T>& operator++();        //prefix ++
   Rational<T> operator++(int); //postfix ++
   Rational<T>& operator--();        //prefix --
   Rational<T> operator--(int); //postfix --

   template<typename U>
   friend std::ostream& operator<<(std::ostream &, const Rational<U> & v);

#if 0
   //does this one need to be a friend? probably safer to!
   //don't think I need this as a rational template....
   template<typename U>
   friend Rational<U> operator+=(const Rational<U> & rhs);

#endif

   template<typename U>
   friend Rational<U> operator+(const Rational<U> & lhs, const Rational<U> & rhs);

   template<typename U>
   friend Rational<U> operator-(const Rational<U> &lhs);

   template<typename U>
   friend bool operator==(const Rational<U> &lhs, const Rational<U> &rhs);

   template<typename U>
   friend bool operator<(const Rational<U>&lhs, const Rational<U>&rhs);


};

template <typename T>
Rational<T>(int, int = 1);

template<typename U>
 std::ostream& operator<<(std::ostream&, const Rational<U>& v);

template<typename U>
 Rational<U> operator+(const Rational<U>& lhs, const Rational<U>& rhs);

template<typename U>
 Rational<U> operator-(const Rational<U>& lhs);

template<typename U>
 bool operator==(const Rational<U>& lhs, const Rational<U>& rhs);

template<typename U>
 bool operator<(const Rational<U>& lhs, const Rational<U>& rhs);

Rational<T>& operator-=(const Rational& rhs);
Rational<T>& operator*=(const Rational& rhs);
Rational<T>& operator/=(const Rational& rhs);
Rational<T>& operator++();        //prefix ++
Rational<T> operator++(int); //postfix ++
Rational<T>& operator--();        //prefix --
Rational<T> operator--(int); //postfix --


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
