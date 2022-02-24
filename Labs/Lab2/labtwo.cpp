//Labtwo.cpp
//Lisa Jacklin
//CS 202
//2/10/2022

#include <iostream>
using std::cout;
using std::endl;


/*
Class requirements :
1. default constructor
2. copy constructor
3. one other constructor
4. deconstructor
note: must provide output so you can see when objects are created, copied or destroyed.
*/


class Labtwo {
public:
	//defalt constructor holds the same name as the class; note specific paramerters
	Labtwo() { cout << "default constructor" << endl; }

	//notice that const Labtwo & c passing by refference another constructor
	Labtwo(const Labtwo& c) { cout << "copy constructor" << endl; }

	//another constructor: parameter constructor
	//remember parameter constructors simply have a specified parameter in ()
	Labtwo(int x) {
		cout << "parameter constructor" << endl;
	}

	//remember deconstructors symbol: ~
	~Labtwo() { cout << "deconstructor" << endl; }
private:
};



