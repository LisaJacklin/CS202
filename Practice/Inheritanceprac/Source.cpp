//first step to building a program that will draw boxes on a screen
//replace the counts in draw() with appropriate graphics libaray calls

#include <iostream>
using std::cout;
using std::endl;

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

	void draw() const;
private:
	int _width;
};

void Square::draw() const {
	//replace with actual graphics library calls
	cout << "Draw square _width = " << _width << endl;

}

int main() {
	Square s1;
	Square s2(3);
	Square s3(8);

	s1.draw();
	s2.draw();
	s3.draw();

}