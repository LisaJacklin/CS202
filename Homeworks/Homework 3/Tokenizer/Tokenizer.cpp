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
#include "Stopwatch.hpp"
#include <fstream>

using std::cout;
using std::endl;

//command line main...
//remember, argc is amount of arguments, argv is the array of them.
int main(int argc, char** argv)
{
	//this allows for a file to be read and taken as an argument
	//rather than standard input
	bool file = false;
	string filename = ""; //allows you to insert a file name 
	bool printing = true;

	//if i is less than the amount of arguments
	for (int i = 1; i < argc; i++) {
		printing = false;
	}
	else {
	 //if the file is large enough to be considered for printing
	 filename = argv[i];
	 file = true;
	}

	//now, more on printing the file
	//if the string from the files says linesonly, it will not print
	if (string(argv[i]) == "--lineonly") {
		printing = false;
	}
	else {
		//if --lineonly is not included in the file
		fileName = argv[i];
		fileMode = true;
	}

	//now...to include a stopwatch function...

}
