#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP


#include <iostream>
#include <chrono>

//create StopWatch class
class StopWatch {
private:
    //time in second sand milliseconds as doubles
    //double seconds;
    //double milliseconds;

    //data members created
    std::chrono::time_point<std::chrono::system_clock> _start, _end;

public:

    StopWatch() {
        //begins the stopwatch
        _start = std::chrono::system_clock::now();

        std::cout << " timer began\n";
    }

    ~StopWatch() {
        _end = std::chrono::system_clock::now();
        //measures the time between start and finish as a double
        std::chrono::duration<double> elapsed_seconds = _end - _start;

        std::cout << "Stopwatch stopped\n";
        //both values should be shown in doubles
        //prints out the process time in milliseconds and seconds ( chrono clock standard) 
        std::cout << " Process time: " << std::chrono::milliseconds(1).count() << " ms\n";
        //note elapsed_seconds comes from line 27.
        std::cout << "Process time: " << elapsed_seconds.count() << "s\n";

    }


};

#endif