#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include <iostream>
using std::ostream;

//template class created
template <typename T> 
class Wrapper {
private:
	T data; //private variable
public:
	//constructor taking a parameter 
	//note that d is then related and turned into a data variable.
	Wrapper(T d) : data(d) {};
	// print function that returns the variable data.
	T print() {return data;} 
};

//need to restate the template here in order for
//the overloading operator to accept the type.
//remember this doesn't need to be a friend!
template <typename T> 
ostream& operator<< (ostream& os, Wrapper<T> w) {
	return os << w.print(); //takes the wrap object and prints it
}

#endif
