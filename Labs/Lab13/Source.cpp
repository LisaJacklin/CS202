//Source.cpp
// Lisa Jacklin
// CS 202 Lab 13
// 4/17/2022
//

#include <iostream>
using std::cout;
using std::endl;

/*
Requirements:
1. write a function template named twice
- takes a parameter x and return x+x.

demonstrate the following code compiles and prints:
cout << twice(2) << endl;
cout << twice(2.3) << endl;
cout << twice(string("hello")) << endl;

2.last line calls twice w a string.
- what happens if it's called using a c-style string?
3. Fix code so twice ("world") works
-HINT: template specialization define a version of twice that takes
  a const char ( pointer).
  - probably want to convert parameter to c++style string...
  
  */


int main() {
	cout << "start of main" << endl;

	cout << "end of main" << endl;
}