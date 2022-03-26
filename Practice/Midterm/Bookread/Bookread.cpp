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

using std::cout;
using std::endl;

//command line main...
//remember, argc is amount of arguments, argv is the array of them.

int main(int argc, char** argv) {
    //this allows for files! 
    bool fileMode = false;
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

    if (!fileMode) {
        cout << "Expected a file as parameter" << endl;
        return 0;
    }
    //now, taking data that is given in the standard form...

}
