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
using std::string;
using std::ostream;

//Abstract Base class
class Box {
	//constructor that sets width and height...
	Box(int w, int h) : _width(w) , _height(h) {	
	}
	~Box (){} //box deconstructor...
	//does this constructor need to be virtual? 

	//accessor functions
	int getWidth() const { return _width;}
	int getHeight() const { return _height; }

	//mutator functions
	void setWidth(int w) { _width = w;}
	void setHeight(int h) {	_height = h;}

	//now virtual functions
	virtual void print(ostream& os) const = 0;
	virtual string type() const = 0;
	//these functions are going to be defined within out derived classes

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