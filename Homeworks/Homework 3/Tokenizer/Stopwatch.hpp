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
	std::chrono::time_point<std::chrono::system_clock> _end;

	//now, setting durations to doubles with variable names
	std::chrono::duration<double> _elapsedSeconds;
	std::chrono::duration<double, std::milli> _elapsedMillis;

public:
	StopWatch() {
		//use this default constructor to start the timer
		_start = std::chrono::system_clock::now();
	}
	//start a function for starting as well
	void start() {
		_start = std::chrono::system_clock::now();
	}

	//now, a function that stops the stopwatch
	void stop() {
		_end = std::chrono::system_clock::now();

		//now, this stopwatch measured the time it took in
		//seconds
		_elapsedSeconds = _end - _start;
		//and milliseconds
		_elapsedMillis = _end - _start;
	}

	//now for elapsed time
	double getElapsedSeconds() {
		return _elapsedSeconds.count();
	}
	
	double getElapsedMillis() {
		return _elapsedMillis.count();
	}
};

#endif