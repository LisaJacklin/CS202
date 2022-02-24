// L4.cpp 
// Lisa Jacklin
// CS 202
// 2/7/2022
// 

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

#include <fstream> // this allows you to open files
#include <string>
#include <sstream>
#include <iomanip>
using std::ofstream; //output
using std::ifstream; //input
using std::fstream;

/*
Requirements:
write a program that reads/writes from a text file.
1. open a text file and display the console contents
2.Query the user for a number n, a line of text, all in one line
3. append n copies of the line of text to the file.

note: when demonstrating your program run more than one, so we can see
that you actually append the text instead of owerwritting the old file.

Optional:
modify program so it counts number of: paragraphs, lines, words, char inside file
Print the reults in colums w headers out to the standard output

*/



bool openFileappend(string filename) {
    //first, this opens a file to be written to.
    std::ofstream fout(filename, std::ios::out | std::ios::app);
    if (!fout) {
        //and is checked to confirm that the file is opened.
        std::cout << "Error opening file." << filename << "\n";
        return false;
    }
    cout << "file opened" << endl;


    if (fout.is_open()) {
        //tells us that the file is opened
        cout << "file is opened to write" << endl;

        //now prompting the user for an integer and a string
        cout << "please enter number of copies to print" << endl;
        cout << "then space and a line youd like to print: " << endl;

        //now  giving these values to be printed to validate what will be printed and how many times
        int numprint;
        string ln;
        cin >> numprint >> ln;
        //cout << "enterd: " << numprint << " and " << ln << endl;

        for (int i = 0; i < numprint; i++) {
            //now prints the  the number of lines for the text
            fout << ln << endl;
            // cout << ln << endl;

        }

        fout.close();

    }
    return true;
}



int main() {
    cout << "beginning of main" << endl;

    std::string fname = "str.txt";
    openFileappend(fname);


    cout << "end of main" << endl;
}
