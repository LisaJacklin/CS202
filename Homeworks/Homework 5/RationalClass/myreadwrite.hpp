#ifndef MYREADWRITE_HPP
#define MYREADWRITE_HPP

//myreadwrite.hpp
// Lisa Jacklin
// CS 202 Homework 5
// 4/23/2022
//
//Note: this code is used for part 2!

#include <iostream>
using std::cout;
using std::cin;

template <typename T>
void myWrite(std::ofstream& w, const T& x) {
	//note that we are writing and reading to a file
	//thus we can use const char *
	w.write(reinterpret_cast<const char*>(&x), sizeof(T));

}

template <typename T>
void myRead(std::ifstream& r, T& x) {
	//cannot use const char otherwise the same var will print
	r.read(reinterpret_cast<char*> (&x), sizeof(T));
}

#endif