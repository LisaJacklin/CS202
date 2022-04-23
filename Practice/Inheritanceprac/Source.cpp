//first step to building a program that will draw boxes on a screen
//replace the counts in draw() with appropriate graphics libaray calls
//1. built a square class
//2. built a rectangle class

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;
using std::shared_ptr;
using std::make_shared;

//virtual base class
class Shape {
public: 
	Shape() : _xloc(0), _yloc(0), _color(0) {
		cout << "Shape ()" << endl;
	}
	void get_location();
	void set_location();
	virtual void draw() =0 ; //this picks which draw function is required
	//note the zero means that there is not draw function in this class
	//so it must go looking for one...
private:
	int _xloc, _yloc, _color; // ...
};


//Base class...
class Square {
public:
	//default constructor  when _width = 1
	Square() : _width(1) {
		cout << "Square()" << endl;
	}
	//default constructor when _width = int w
	Square(int w) : _width(w) {
		cout << "Square (" << w << ")" << endl;
	}

	~Square(){}

	void draw() const;
	//common functions: set_location, get_location, set_color, get_color...
private:
	//when this data is private, we have to call the base constructor
	//whenever we want to use this data which makes it easy!!! 
	int _width;
	int _xloc, _yloc, _color; //...
};
void Square::draw() const {
	//replace with actual graphics library calls
	cout << "Draw square _width = " << _width << endl;

}

//remember! everything in a inherited class here is just additions 
//are adjustments and additional pieces not included in the base class
class Rectangle : public Square {
public:
	//default constructor  when _width = 1
	Rectangle() : Square(), _height(1) { 
		//notice the Square() this allows us to access private Square
		cout << "Rectangle()" << endl;
	}

	//default constructor when _width = int w
	Rectangle(int w, int h) : Square(w), _height(h){
		cout << "Rectangle (" << w << ", " << h << ")" << endl;
	}

	~Rectangle() {}

	void draw() const;
	//common functions: set_location, get_location, set_color, get_color...
private:
	int _height;
};

//having issues with _width in this code
void Rectangle::draw() const {
	//replace with actual graphics library calls
	cout << "Draw Rectangle _width = " << _width 
		 << " x " << _height << endl;
}

int main() {
#if 0
	//basic idea and how to use these functions and classes
	Square s1;
	Square s2(3);
	Square s3(8);
	Rectangle r1;
	Rectangle r2(4, 6);

	s1.draw();
	s2.draw();
	s3.draw();

	//this is easier and better to do using a vector, and 
	//a for loop to draw each in. Now, this isn't the best option...
	vector <Square> s;
	s.push_back(Square());
	s.push_back(Square(3));
	s.push_back(Square(23));

	for (auto i : s) {
		i.draw();
	}
#endif

#if 0
	//get shared_ptr to work!
	Shape* u = new Square();
	shared_ptr<Shape> sPtr = make_shared<Square>();

	auto sPtr1 = make_shared <Square>();
	auto sPtr2 = make_shared<Square> (10);
	auto sPtr3 = make_shared<Rectangle>(8, 9);

	sPtr1->draw();
	sPtr2->draw();
	sPtr3->draw();

#endif

	vector <shared_ptr<Shape>> s;
	s.push_back(make_shared<Square>());

	//don't use new and delete
	vector <Shape*> v;
	v.push_back(new Square());
	v.push_back(new Square(10));
	v.push_back(new Rectangle(8, 9));
	v[2]->set_location(22);
	v.push_back(new Rectangle(80, 90));
	//can mix and match in container
	for (auto s : v)
		s->draw(); //resolves at run time

	//never called delete

#if 0
	//didn't work - always called square::draw9)
	//want polymorphism
	vector <Shape> v;
	v.push_back(new Square(25));
	v.push_back(new Rect(8, 9));
	for (auto s : v)
		s.draw() //.operator must resolve at compile
#endif
}