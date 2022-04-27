//Source.cpp
// Lisa Jacklin
// CS 202 FINAL
// 4/25/2022
//

#include <iostream>
using std::endl;
using std::cout;

#include <iostream>
#include "columns.hpp"
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

using std::ifstream;
using std::cout;
using std::endl;

/*
Requirements:
-turn the program from midterm to be able to handle 3 columns
- or rather: into a function/class that allows for any amount of columns....

  ideas:
  setw(4) for the space between the columns?
  - figure out one page length in column 1
  that way i know how many paragraphs I need to place
  in the other column....
*/


int main(int argc, char** argv) {
    //remember this has to be true to read!
    bool fileMode = true;
    //file name to read
    string fileName = "980.txt";//Check this is included here in Final source
    bool printing = true;

#if 0 //don't think I need this data in this case
    for (int i = 1; i < argc; i++) {

        if (string(argv[i]) == "--lineonly") {
            printing = false;
        }
        else {
            //must be file name
            fileName = argv[i];
            fileMode = true;
        }

    }

#endif

    //error tester
    if (!fileMode) {
        cout << "Expected a file as parameter" << endl;
        return 0;
    }

    //the following code should be okay...simply need to adjust the class functions etc.
    //Maybe add an option for the user to change the columns amount....?
    vector<Token> tokens;
    ifstream is(fileName);

    Token::readLines(tokens, is);

    if (printing) {
        Token::printTokens(cout, tokens);

    };
}