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