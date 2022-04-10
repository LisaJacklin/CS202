#ifndef BOX_HPP
#define BOX_HPP

//Box.cpp
// Lisa Jacklin
// CS 202 Homework 4
// 4/5/2022
//

/*
* Requirements:
* - write a set of classes representing boxes (which can be displayed)
* - include width and height and can be printed to screen or file
* - boxes can be hollow, filled or checkered...
*
* Abstract base called Box,
* Derived: filledBox, HollowBox, and CheckeredBox
*
*
*/

#include <iostream>
using std::cout;
using std::endl;

//Abstract Base class
class Box {

	Box() {
		cout << "box base constructor" << endl;
	}
private:
	int _width;
	int _height;
};

class FilledBox : public Box {
public:
private:

};

class HollowBox : public Box {
public:
private:
};

class CheckeredBox : public Box {
public:
private:
};

#endif