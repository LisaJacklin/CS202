//lab11.cpp
// Lisa Jacklin
// CS 202
// 4/1/2022
//

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Base {
public:
	Base() { //base class constructor
		cout << "Constructing a default Base object" << endl;
	}

	Base(int i) : _var(i) { //base class variable constructor
		cout << "Base constructor with _var: " << _var << endl;
	}

	~Base() { //deconstructor of base class
		_var = 1;
		cout << < "deconstructor called _var number: " << _var << endl;
	}
private:
	int _var;
};

class second : public Base {
public:
	second(string s, int i) : Base(i), _name(s) {
		cout << "Constructor with a name: " << _name << endl;
	}
	~second() {
		cout << "destructor of : " << _name << endl;
	}
private:
	string _name;
};

int main() {
	cout << "start of main" << endl;

	Base a;
	Base b(3);

	//second c;
	second c("Jacob", 3);


	cout << "end of main" << endl;
}