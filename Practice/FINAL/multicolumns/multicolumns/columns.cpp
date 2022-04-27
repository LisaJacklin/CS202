// columns.cpp
// Lisa Jacklin
// CS 202 Midterm Part 2
// 3/24/ 2022
//

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
-turn the program from bookread.cpp/hpp into the 
  then add two columns 38 char 4 space 38 char

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
    string fileName = "980.txt";
    bool printing = true;

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
    //error tester
    if (!fileMode) {
        cout << "Expected a file as parameter" << endl;
        return 0;
    }

    vector<Token> tokens;
    ifstream is(fileName);

     Token::readLines(tokens, is);

    if (printing) {
        Token::printTokens(cout, tokens);

    };

}