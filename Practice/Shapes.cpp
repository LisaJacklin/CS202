// start from scratch - create a hierarchy of shapes
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

//start with the abstract base class
class Shape {
public:
  Shape() : _location(0) { cout << "Shape()" << endl; }
  Shape(int l) : _location(l) { cout << "Shape(" << l << ")" << endl; }
  ~Shape() {}
  // these will be used by all derived class - DRY
  int get_location() const;
  void set_location(int l);
  // =0 makes this an abstract base class and EVERY
  // derived class MUST create its own version of draw()
  virtual void draw() const =0;
private:
  int _location;  // every object has a location (should be a Point)
};

class Square : public Shape {
public:
  Square() : _width(1) { cout << "Square()" << endl; }
  Square(int w) : _width(w) { cout << "Square(" << w << ");" << endl; }
  void draw() const ;
protected:
  int _width;
};

class Rect : public Square {
public:
  Rect() : Square(), _height(1) { cout << "Rect()" << endl; }
  Rect(int w, int h) : Square(w), _height(h) 
    { cout << "Rect(" << w << "," << h << ");" << endl; }
  void draw() const ;
private:
  int _height;
};

class Triangle : public Rect {
};

class Circle : public Shape {
public:
private:
  int _radius;
};

void Shape::set_location(int l) { _location=l; }
int  Shape::get_location() const { return _location; }
void Square::draw() const
{
  cout << "Drawing Square(" << _width << ") at loc=" << get_location() << endl;
}
void Rect::draw() const
{
  cout << "Drawing Rect " << _width << "x" << _height
       << " at loc=" << get_location() << endl;
}

int main()
{
  // OK for now, but ... use unique_ptr
  vector< Shape * > v;
  v.push_back( new Square() );
  v.push_back( new Square(10) );
  v.push_back( new Rect() );
  v.push_back( new Rect(15,30) );

  for ( auto s : v )
    s->draw();
}
