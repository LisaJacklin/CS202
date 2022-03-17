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
	//data for money value
	int value;
public:
	//no money constructor
	Money() : value(0) {

	}
	//money value turns to value of i
	Money(int i) : value(i) {

	}

	//constructor that takes a double
	Money(double d) {
		cout << d << endl;

		//sets a cents value to a dollar value
		d *= 100;
	}

	//constructor that takes dollars and cents
	Money(int d, int c) {
		value = d * 100; //sets dolar value
		value += c; //sets value in cents
	}

// other operators that can be defined within the class!!!
	Money& operator += (const Money& two) {
		value += two.value;
		return *this;
}
	Money& operator -=(const Money& two) {
		value -= two.value;
		return *this;
	}
	Money& operator /=(const double two) {
		value /= two;
		return *this;
	}
	Money& operator *= (const double two) {
		value *= two;
		return *this;
	}
};

//Boolean Operators
bool operator==(const Money& one, const Money& two) {
	return one.value == two.value;
 }
bool operator!=(const Money& one, const Money& two) {
	//return one.value != two.value;
	return !(one == two); //values are not equal
 }
bool operator>(const Money& one, const Money& two) {
	return one.value > two.value;
 }
bool operator<(const Money& one, const Money& two) {
	return !(one>two || one == two) ;
 }
bool operator>=(const Money& one, const Money& two) {
	//return one.value >= two.value;
	return one > two || one == two;
 }
bool operator<=(const Money& one, const Money& two) {
	//return one.value <= two.value;
	return one == two || one < two;
 }

//Math Operators
Money operator/(const Money& one, const double two) {
	auto temporary = one;
	temporary/= two; //this uses an operator defined in Money class
	return temporary;
 }
Money operator+(const Money& one, const Money& two) {
	auto temporary = one;
	temporary.value += two.value; // value is amount of money in cents
	return temporary;
 }
Money operator-(const Money& one, const Money& two) {
	auto temp = one;
	temp.value -= two.value;
	return temp;
 }
Money operator*(const Money& one, const double two) {
	auto temp = one;
	temp.value *= two;
	return temp;
 }

//need another *operator
Money operator* (const Money& one, const Money& two) {
	return one * two;
}

//Stream Operators
std::ostream& operator<<(std::ostream& one, const Money& coins) {
	int value = coins.value;
	bool Negative = value < 0;
	//need to make sure to include negative option!
	if (Negative) {
		one << " - ";
		value *= -1;
	}

	//and now to make sure it displays as a dollar value
	one << "$" << (value / 100) << ".";
	if (value % 100 < 10) {
		one << "0" << (value % 100);
	}
	else one << (value % 100);
	return one; //returns the stream values
 }

#endif