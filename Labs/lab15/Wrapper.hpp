#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include <iostream>
using std::ostream;

//template class created
template <typename T> 
class Wrapper {
private:
	T data;

public:
	//constructor taking a parameter 
	Wrapper(T d) : data(d) {};
	// print function.
	T print() {return data;} 

};

template <typename T>
ostream& operator<< (ostream& os, Wrapper<T> w) {
	return os << w.print();
}


#endif
