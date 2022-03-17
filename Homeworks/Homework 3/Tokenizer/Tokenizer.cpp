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
#include <ostream>
#include <istream>
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::istream;
using std::ostream;
using std::getline;
using std::istringstream;
using std::cout;
using std::endl;

//SEPARATE INTO CORRECT FILES
struct TokenAndPosition {
	string _token;
	int _line;
	unsigned int _column;
};
vector<string> lineToTokens(const string& line);
vector<TokenAndPosition> readLines(istream& is);
void printTokens(ostream& os, const vector<TokenAndPosition>& tokens);

vector<string> linestoTokens(const string& line) {
	vector<string> readMe;
	//the code below will help me finish readlines function
	istringstream is(line);
	string token;

	while (true) {
		//is takes in the token values from the text.
		is >> token;
		//once again, testing to make sure that the istringstream 
		//isn't have errors or at the eof.
		if (!is) {
			if (is.eof()) {
				break;
			}
			else return readMe;
		}
		//pushes the token value to the vector
		readMe.push_back(token);

	}
}
vector<TokenAndPosition> readLines(istream& is) {
	vector<TokenAndPosition> readMe;
	int line = 0; //starts at line zero
	string lines; //and is given a string value

	while (true) {
		getline(is, lines); //pulls the stream and the line
		if (!is) {
			if (is.eof()) {
				//were have finished reading the files
				break;
			}
			//something went wrong...
			return readMe;
		}

		//now to read the lines if no errors and eof occur
		line++;
		//this calls to another vector that is built above
		vector<string> tokens = linestoTokens(lines);
		for (string s : tokens) {
			//now, using code from linestotokens,
			Token t;
			t.token = s;
			t.line = lineNum;
			t.column = line.find(t.token);
			toRet.push_back(t);
		}
	}
}


void printTokens(ostream& os, const vector<TokenAndPosition>& tokens) {
	for (Token t : tokens) {
		os << "line " << t.line << ", Column " << t.column << " : \ " << t.token
			<< " \ " << endl;
	}
}

int main()
{
	cout << "start of main" << endl;

	cout << "end of main" << endl;
}
