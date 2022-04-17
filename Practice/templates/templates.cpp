//templates.cpp
//CS202 4.12 lecture
//sample code

#include <iostream>
using std::cout;
using std::endl;

#if 0
void swap(int& x, int& y) {
	int t = x; x = y; y = t;}
void swap(double& x, double& y) {
	double t = x; y = x; y = t;}
#endif

//note that swaptype should usually be represented by T, but 
//for my understanding right now, I did not use this
template <typename SwapType>
void swap(SwapType& x, SwapType& y) {
	SwapType t = x; x = y; y = t;
}

int main() {
	double a = 10.5;
	double b = 20.5;
	cout << "a= " << a << "b= " << b << endl;
	swap(a, b);
	cout << "After swap: " << endl;
	cout << "a= " << a << "b= " << b << endl;

	int c = 100;
	int d = 200;
	cout << "c= " << c << "d= " << d << endl;
	swap<int>(c, d);
	cout << "After swap: " << endl;
	cout << "c= " << c << "d= " << d << endl;

}
//