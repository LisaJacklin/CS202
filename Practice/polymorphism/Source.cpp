//source.cpp I called it polymorphism.cpp
// Lisa Jacklin
// CS 202 practice 
// 4/7/2022
//

#include <iostream>
using std::endl;
using std::cout;

//start with the abstract base class
class Shape {
public:
	Shape() : _location(0) {
		cout << "Shape()" << endl;
	}

	Shape(int l) : _location(l) {
		cout << "Shape(" << l << ")" << endl;
	}

	~Shape() {}

	// these will be used by all derived class - DRY
	int get_location();
	void set_location(int l);
	// = 0 makes this an abstract base class and EVERY
	//derived class MUST create its own version of draw()
	//way to inforce this!!

	virtual void draw() const = 0;

private:
	int _location; // every object has a location ( should be apoint)
};
void Shape::set_location(int l) {
	_location = 1;
}
int Shape::get_location() {
	_location = -2345;
	return _location;
}

//derived class from base Shape
class Square : public Shape {
public:
	Square() : _width(1) {
	cout << "Square() " << endl;
   }
	Square(int w) : _width(w) {
		cout << "Square(" << w << ")" << endl;
	}
	void draw() const;

private:
	int _width;
};
void Square::draw() const {
	cout << "Drawing Square(" << _width << ") at loc = " <<
		get_location() << endl;
}

//derived class from the derived class square
class Rect : public Square {
public:
	Rect() : _height(1) {
		cout << "Rect()" << endl;
	}
	Rect(int w, int h) : Square(w), _height(h) {
		cout << "Rect (" << w << "," << h << ")" << endl;
	}
	void draw() const;
private:
	int _height;
};
void Rect::draw const{
	cout << "drawing Rect" << _width << "x" << _height << ") at loc + " 
	<< get_location() < endl;
}

int main() {
	cout << "start of main" << endl;

	//Shape s; //an abstract class cannot use this because no draw()
	Square s;
	Square s1(10);



	cout << "end of main" << endl;
}