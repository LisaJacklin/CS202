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
1. functionc contains exactly one statement (x)
2. functionb declares an object of class ( construct and destruct not)
3. output!
- starting main (X)
- object constructed message
- starting function b (X)
- object destruction message
- cought an exception: function c threw (included but not operating)
- ended normally

*/

class labs {
    labs() {
        cout << "labs constructor" << endl;
    }
    ~labs() {
        cout << "labs deconstructor" << endl;
    }
};

void functionC(){
    //your code here
    std::runtime_error("Function C threw std::runtime_error");
}

void functionB(){
    labs L; // not taking my class parameter...
    cout << "Starting functionB()" << endl;
    functionC();
    cout << "Ending functionB()" << endl;
}

void functionA(){
    try {
        //function B moved into my try 
        functionB();
    }
    catch (const std::exception &e) {
        cout << "Caught an exception: " << e.what() << endl;
    //since this line is to tell if it's caught, I placed it
        //within my catch with e being the exception.
    }
}
int main() {
    cout << "Starting main()" << endl;
    functionA();
    cout << "Ended normally." << endl;
    return 0;
}
