// Lab8.cpp
//Lisa Jacklin
//CS 202
// 3/1/2022

#include <iostream>
using std::cout;
using std::endl;

/*
Requirements:
1. create a function with a static local variable.
- demonstrate that it keeps its val. between calls.
3. create a static member variables in a class.
- prints out when it's constructed. 
- variable should count the number of objects in class that exists.
 - must be declared in the .cpp and .hpp
 4. call a static memeber function w/o using an object.
  - prints the number of objects and show how to call w/o object.
*/

//creating a constant local variable.


//now a class
class count {
public:
	count() {
		cout << "default constructor being called" << endl;
		_numberClass++;
	}

	static int classCount() {
		return _numberClass;
		cout << "Number Of Existing Class Objects: " << _numberClass << endl;
	}

private:
	static int _numberClass;
};

//create a function with a static variable w/o an object
//FIX THIS WILL NOT EXECUTE
void staticCounter() {
	 static int counter = 0;

	//since this is a counter,
	//this will add a digit for each time staticCounter is called
	counter++;
	cout << "StaticCounter function called" << endl;
	cout << "counter : " << counter << endl;
}

int main()
{
	cout << "start of main" << endl;

	staticCounter();


	cout << "end of main " << endl;
}

