// Bookread.cpp 
// Lisa Jacklin
// CS 202 MT code 1
// 3/24/2022
//

#include <iostream>
using std::cout;
using std::endl;

/*
Requirements: 
- HW3 additional program 1!!!
- program that reads a book (project gutenberg)
- outputs the text based on a given character wrapping  value.

Notes:
- use a wrap of 50 to start with.
- use the HW3 tokenizer to help with this program!

HW3AP1 Notes:
std::vector <std::string> paragraphs;
- have a vector with two strings; ( tokenizer rids extra space)

*/

#include <iostream>
#include "bookread.hpp"
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    bool fileMode = true;

    string fileName = "readme.txt";
    bool printing = true;

    for (int i = 1; i < argc; i++) {
        //adjusted for additional program 1 
        if (string(argv[i]) == "--html") {
      
            printing = false;
        }
        else {
            //must be file name
            fileName = argv[i];
            fileMode = true;
        }

    }
    //error protection
    if (!fileMode) {
        cout << "Expected a file as parameter" << endl;
        return 0;
    }

    vector<Token> tokens;
    ifstream is(fileName);
    istream& s = is;

    //tokens = paragraphs(s);

    //Token::printTokens(cout , tokens);
    
}
