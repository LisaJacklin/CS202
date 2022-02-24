//Lab3.cpp
//Lisa Jacklin
//CS 202
//2/12/2022

#include <iostream>
using std::cout;
using std::endl;
#include <memory>

/*
Requirements:
1. create raw pointer to object in class
2. Unique pointer of an object in class.
- notes this one should be created with "other constructor"
3. transfer ownership of the object to different unique pointer
4.call the member function of the object through the unique pointer...
5. make a shared pointer to a dynamic object in class
6. make another shared pointer pointing at the same object.

note: print a line on the console for each item
- be sure to use make_shared and make_unique ; do not call constructors
for shared_ptr and unique_ptr directly.

*/

//class from lab 2
class Labtwo {
public:
	//defalt constructor holds the same name as the class; note specific paramerters
	Labtwo() { cout << "default constructor" << endl; }

	//notice that const Labtwo & c passing by refference another constructor
	Labtwo(const Labtwo& c) { cout << "copy constructor" << endl; }

	//another constructor: parameter constructor
	//remember parameter constructors simply have a specified parameter in ()
	Labtwo(int x) { cout << "parameter constructor" << endl; }

	//remember deconstructors symbol: ~
	~Labtwo() { cout << "deconstructor" << endl; }

	//Addition for Lab 3! A member function
	void whatever() { cout << "whatever" << endl; }

private:
};

int main() {
	cout << "start of main" << endl;

	//raw pointer:
	cout << "raw pointer created" << endl;
	Labtwo* ptr = new Labtwo;
	ptr->whatever(); // note the arrow accesses a function of an object
	delete ptr; // must be included with a raw pointer; avoid memory leak

	//now a unique pointer
	cout << "unique pointer created" << endl;
	auto uPtr = std::make_unique<Labtwo>();
	//now to transfer ownership of this pointer
	cout << "unique pointer moved" << endl;
	auto uPtr2 = std::move(uPtr);

	//call the member function of the object through the pointer...
	cout << "calling function from pointer" << endl;
	uPtr2->whatever();

	//use a shared pointer
	cout << "shared pointer created" << endl;
	auto sPtr = std::make_shared <Labtwo>();
	//and another pointer that points to the same object
	cout << "additional shared pointer to same member " << endl;
	auto sPtr2 = sPtr;

	cout << "end of main" << endl;
}