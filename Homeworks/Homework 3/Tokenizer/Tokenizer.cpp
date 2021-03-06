// Tokenizer.cpp 
// Lisa Jacklin
// CS 202
// 3/7/2022
//

/*
Requirements:
- program that takes input from standard into or a file(Command line)
- prints the tokens along with line and column each token occurs at.

- test program with project gutenberg book 
- determine how long it takes to process it.
-diference in time if you skip the output?
-measure in MB/second


Notes: 
- use find member in string class to find positions;
   - readline reads token first with linetotoken then find member

- because we may reuse this code later, work with std::istream and std::ostream.
- time program w/ linetotoken/readline and w/ printtokens.

- have program determine which choise to use by checking the command line
*/

#include <iostream>
#include "tokenizer.hpp"
#include "stopwatch.hpp"

#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    bool fileMode = true;

    string fileName = "tokenizer.txt";
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

    vector<Token> tokens;
    ifstream is(fileName);

    StopWatch watch;
    tokens = readLines(is);

    if (printing) {
        printTokens(cout, tokens);
    }
    watch.stop();

    cout << "Took " << watch.getElapsedSeconds() << " seconds" << endl;

}