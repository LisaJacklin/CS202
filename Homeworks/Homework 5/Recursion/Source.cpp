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
	if (n < 1) return 0;
	if (n == 1 || n == 2) return 1; // if the number is 1 or 2, returns 1

	int total = 0;
	int one = 1; //if n = 1,
	int two = 1; // if n = 2 answer is the same as n  = 1

	for (int i = 2; i < n; i++) { //esentially finds the answer for n <=2.
		//can this be done with a swap?
		total = one + two;
		one = two;
		two = total;
	}
	return total; //produces the answer for the loop.
}

int ack(int m, int n) {
	//Ackermann's number 
	//Note: use the piecewise function given in homework for these numbers

	//n + 1 if m = 0
	if (m == 0) return n + 1;
	//A(m-1,1) if m>0 and n=0
	if (m > 0 && n == 0) return ack(m - 1, 1);
	//A(m-1, A(m,n-1)) if m>0 and n > 0
	if (m > 0 && n > 0) return ack(m - 1, ack(m, n - 1));

	return -1;
}


int main() {
	cout << "start of main" << endl;

	cout << "Fibonacci Sequence" << endl;
	for (int i = 0; i < 20; i++) {
		cout << "fib(" << i << "): " << fib(i) << "==" << fib_loop(i) << " total\n";
	}

	//two spaces between fibonacci sequence and ackermanns sequence
	cout << endl << endl;

	cout << "ACK" << endl;
	//two variable for loop for n and m
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6 - i; j++) {
			cout << "ack(" << i << ", " << j << ") = " << ack(i, j) << endl;
		}
	}

	cout << "end of main" << endl;
}