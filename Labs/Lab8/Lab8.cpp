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

//now a class
class countThings {
public:
	countThings() {
		cout << "default constructor being called" << endl;
		_numberClass++;
		//cout << "There is now " << _numberClass << " stuff in existence" << endl;
	}

	~countThings() {
		cout << "destructor" << endl;
		_numberClass--;
		//cout << "There is now " << _numberClass << " stuff in existence" << endl;
	}

	static int classCount() {
		cout << _numberClass << endl;
		return _numberClass;
	}
private:
	 static int _numberClass;
};

//create a function with a static variable w/o an object
void staticCounter() {
	 static int counter = 0;

	//since this is a counter,
	//this will add a digit for each time staticCounter is called
	counter++;
	cout << "StaticCounter function called" << endl;
	cout << "counter : " << counter << endl;
}

//This is important!!! this initializes the value!!
int countThings::_numberClass = 0;

int main()
{
	cout << "start of main" << endl;

	countThings a = countThings();
	countThings b = countThings();

	staticCounter();
	staticCounter();
	staticCounter();
	staticCounter();

	//countThings::classCount();
	cout << "Number Of Existing Class Objects: " << countThings::classCount << endl;
	cout << "end of main " << endl;
}

