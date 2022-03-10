// lab9.cpp 
// Lisa Jacklin
// CS 202
// 3/10/2022
//

#include <iostream>
#include "Complex.hpp"

using std::cout;
using std::endl;

/*
Requirements:
1. implement a complex number class named complex.
 - separate into complex.cpp and complex.hpp
 2.implement:
 - constructor that takes two doubles, real and complex.
 - constructor that takes one parameter setting real part.
    - note provide a default value of zero for second parameter.
3. implement stream insertion operator (for complex numb)
4. implement + operator for complex numbers.
5. implement += for complex numbers. 
6. implement one in terms of the other (using 4 and 5)
7. write main.cpp demonstrating operators defined.
- code to use:
cout << 1+Complex (2,3) << endl;
8. for this to work, you must make the right choice of global or 
member function for operator +;
*/

int main() {
    Complex c(4, 8);
    cout << c << endl;

    //sample code to use and some variations
    cout << 1 + Complex(2, 3) << endl;
    cout << 1.0 + Complex(2, 3) << endl;
    cout << c + Complex(2, 3) << endl;
}