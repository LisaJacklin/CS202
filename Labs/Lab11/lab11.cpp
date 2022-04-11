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
		cout << "Constructing a default Base object" << endl;}

	Base(int i) : _var(i) { //base class variable constructor
		cout << "Base constructor with _var: " << _var << endl;}

	~Base() { //deconstructor of base class
		cout << "deconstructor called _var number: " << _var << endl;}
private:
	int _var;
};

class Derived : public Base {
public:
	Derived(): _name("")  { //if no name is given...though might workout without? test that
		cout << "Constructing a default Derived object." << endl;}

	Derived(string s, int i) : Base(i), _name(s) {
		cout << "Constructor with a name: " << _name << endl;}

	~Derived() {
		cout << "destructor of object named:  " << _name << endl;}

private:
	string _name;
};

int main() {
	//cout << "start of main" << endl;

	//the code below is given from lab 11 guidelines
	{Base b; }
	cout << endl;
	{Base b(13); }
	cout << endl;

	{Derived d; }
	cout << endl;

	{Derived d("Eliza", 16); }


	//cout << "end of main" << endl;
}