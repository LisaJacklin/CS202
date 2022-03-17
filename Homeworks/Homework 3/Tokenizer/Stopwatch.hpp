#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP


#include <iostream>
#include <chrono>

#include <ctime>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;

//create StopWatch class
class StopWatch {
//probably better to start with the base line 
	//rather than the mess my HW1 code is...
private:
	//chrono using a system clock to mark variables start and stop
	std::chrono::time_point<std::chrono::system_clock> _start;
	std::chrono::time_point<std::chrono::system_clock> _endl;

public:
	StopWatch() {
		//use this default constructor to start the timer
	}

	//now, a function that stops the stopwatch
	void stop() {

	}
};

#endif