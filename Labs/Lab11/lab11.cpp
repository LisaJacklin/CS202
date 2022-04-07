//lab11.cpp
// Lisa Jacklin
// CS 202
// 4/1/2022
//

#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	Base() {
		cout << "Constructing a default Base object" << endl;
	}
	Base(int _var) {
		_var = 1;
		cout << "variable number" << _var << endl;
	}
private:
	int _var;
};

int main() {
	cout << "start of main" << endl;

	cout << "end of main" << endl;
}