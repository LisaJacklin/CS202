//exceptions.cpp
//Lisa Jacklin
//CS 202 Lab 10
//3/30/2022

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
Requirements:
1. functionc contains exactly one statement
2. functionb declares an object of class ( construct and destruct not)
3. output!
- starting main
- object constructed message
- starting function b
- object destruction message
- cought an exception: function c threw
- ended normally

*/

void functionC(){
    //your code here
}

void functionB(){
 // your code here
    cout << "Starting functionB()" << endl;
    functionC();
    cout << "Ending functionB()" << endl;
}

void functionA(){
    functionB();
    // your code here
    cout << "Caught an exception: " << e.what() << endl;
    // your code here
}
int main() {
    cout << "Starting main()" << endl;
    functionA();
    cout << "Ended normally." << endl;
    return 0;
}
