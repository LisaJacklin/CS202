//money.hpp
//Lisa Jacklin
//CS 202
//3/12/2022

#ifndef MONEY_HPP
#define MONEY_HPP

/*
Requirements:
-write class to hold an amount of money w/ overloaded operators
- money is counted IN CENTS
- output is standard form.

Following operations:
- == and !=
- < and <=
- >= and >
- += and +
- -= and -
- (* and *=)
- / and /=

- print money to ostream.
- include a default constructor w/ 0 money,
- include constructor that takes two integers (dollars and cents)
- one constructor that takes a double

- should be able to assign money objects and copy them.

*/
#include <iostream>
#include <ostream>

using std::cout;
using std::endl;

class Money {
	//Boolean Operators
	friend bool operator==(const Money& one, const Money& two);
	friend bool operator!=(const Money& one, const Money& two);
	friend bool operator>(const Money& one, const Money& two);
	friend bool operator<(const Money& one, const Money& two);
	friend bool operator>=(const Money& one, const Money& two);
	friend bool operator<=(const Money& one, const Money& two);

	//Math Operators
	friend Money operator/(const Money& one, const double two);
	friend Money operator+(const Money& one, const Money& two);
	friend Money operator-(const Money& one, const Money& two);
	friend Money operator*(const Money& one, const double two);

	//Additional Operators
	friend std::ostream& operator<<(std::ostream&, const Money&);

private: 
	int value;
public:
	//no money constructor
	Money() : value(0) {

	}

	//constructor that takes a double
	Money(double d) {

	}
	//constructor that takes dollars and cents
	Money(int d, int c) {

	}

};

//Boolean Operators
bool operator==(const Money& one, const Money& two) {

 }
bool operator!=(const Money& one, const Money& two) {

 }
bool operator>(const Money& one, const Money& two) {

 }
bool operator<(const Money& one, const Money& two) {

 }
bool operator>=(const Money& one, const Money& two) {

 }
bool operator<=(const Money& one, const Money& two) {

 }

//Math Operators
Money operator/(const Money& one, const double two) {

 }
Money operator+(const Money& one, const Money& two) {

 }
Money operator-(const Money& one, const Money& two) {

 }
Money operator*(const Money& one, const double two) {

 }

//Additional Operators
friend std::ostream& operator<<(std::ostream&, const Money&);

#endif