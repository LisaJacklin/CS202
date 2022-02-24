// Lab5.cpp 
//Lisa Jacklin
//CS 202
//2/22/2022

/*
Requirements: 
-open and read from binary file
1. read integers from file
2. print the number of integers, sum and average.

*/

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

using std::cout;
using std::endl;
using std::ios;

int main()
{
    //call the binary data from file data.dat
    std::ifstream input("data.dat", ios::binary | ios::in);

    //place all values into a vector for easy sum, size, and average.
    std::vector <int> data;
    int i;
    cout << "reading data.dat file" << endl;

    //test that the input file is being read and opened properly
    while (true) {
        input.read(reinterpret_cast<char*> (&i), sizeof(int));

        if (!input) {
            if (input.eof()) {
                break;
            }
            cout << "Reading error" << endl;
            return 0;
        }
        data.push_back(i);
    }

    //now that the file is read,
    //display the number of integers
    cout << "Number of integers: " << data.size() << endl;

    //now the sum, and average;
    int sum = 0;
    double average;

    for (int n : data) sum += n;

    average = sum / data.size();

    cout << "Integer Sum: " << sum << endl;
    cout << "Integer Average: " << average << endl;
}

