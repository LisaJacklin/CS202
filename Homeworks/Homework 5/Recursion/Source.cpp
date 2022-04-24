//source.cpp
// Lisa Jacklin
// CS 202 Homework 5 Recursion
// 4/20/2022
//

#include <iostream>
using std::cout;
using std::endl;

//note the use of integer functions because everything delt w/ is a number
int fib(int n) {
	//returns the nth number of the sequence
	if (n == 0) return 0; // nothing there, nothing to give
	if (n == 1) return 1; //first number in the sequence is 1
	//note the equation here comes from the equation given 
	//in homework guide Fn = Fn-1 + Fn-2
	return fib(n - 1) + fib(n - 2);

}

int fib_loop(int n) {
	//returns the nth number in the sequence without recursion...
	return 0;
}

int ack(int m, int n) {
	//Ackermann's number 

	return 0;
}


int main() {
	cout << "start of main" << endl;

	cout << "Fibonacci Sequence" << endl;
	for (int i = 0; i < 20; i++) {
		cout << "fib(" << i << "): " << fib(i) << endl;
	}


	cout << "end of main" << endl;
}