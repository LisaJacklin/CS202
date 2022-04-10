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
using std::unique_ptr;

//Abstract Base class
class Box {
public:
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

//operator funtion that draws to box to ostream
ostream & operator << (ostream & os, const Box & b) {
	b.print(os); //PRINT STILL NEEDS TO BE DEFINED!!!
	return os;
}

class FilledBox : public Box {
public:
	//default constructor of 1x1 box
	FilledBox(): Box (1,1) {}
	//user specified width and height
	FilledBox(int h, int w) :Box (w, h) {}
	//now type that returns string as appropriate
	string type() const{
		return "Filled";
	}

	//and dont forget the print function!!!!
	void print(ostream& os) const {
		for (int i = 0; i < getHeight(); i++) {
			for (int j = 0; j < getWidth(); j++) {
				os << "x";
			}
			os << endl;
		}
	}

//since all derived classes are the same box shape, 
// no additional private integers needed.
};

//factory function
unique_ptr<Box> boxFactor(char c, int w, int h) {
	//needs to take a character f, h, or c... and a width and height...
}

class HollowBox : public Box {
public:
	//default constructor of 1x1 box
	HollowBox() : Box(1, 1) {}
	//user specified width and height
	HollowBox(int h, int w) :Box(w, h) {}
	//now type that returns string as appropriate
	string type() {
		return "Hollow";
	}
	void print(ostream& os) const {
		
	}
};

class CheckeredBox : public Box {
public:
	//default constructor of 1x1 box
	CheckeredBox() : Box(1, 1) {}
	//user specified width and height
	CheckeredBox(int h, int w) :Box(w, h) {}
	//now type that returns string as appropriate
	string type() {
		return "Checkered";
	}
	void print(ostream& os) const {

	}
};

#endif