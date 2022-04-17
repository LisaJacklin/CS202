//Source.cpp
// Lisa Jacklin
// CS 202 Lab 15
// 4/17/2022
//

#include <iostream>
using std::cout;
using std::endl;

#include "Wrapper.hpp"
using std::string;

/*
Requirements:
- write a class template "wrapper" containing an object of any type
- need constructor that takes object w type.
- should contain an overloaded operator <<
	- will insert the wrapped object into the ostream. ( pr a public print() )
	-this operator doesn't need to be a friend.

- place the class in a Wrapper.hpp file
- do not define your member class function in the class def.
- demonstrate:
Wrapper<int> w{2};
Wrapper <string> s {"Hellow world!"};
cout <<  w << " " << s << endl;

*/

int main() {
	cout << "start of main" << endl;

	Wrapper<int> w{ 2 };
	Wrapper <string> s{ "Hello world!" };
	cout << w << " " << s << endl;

	cout << "end of main" << endl;
}