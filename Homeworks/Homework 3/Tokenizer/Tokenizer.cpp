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
#include <fstream>
#include <vector>

using std::vector;
using std::string;
using std::istream;
using std::ostream;
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

vector<TokenAndPosition> readLines(istream& is) {

}
vector<string> linestoTokens(const string& line) {
	 
}

void printTokens(ostream& os, const vector<TokenAndPosition>& tokens) {

}

int main()
{
	cout << "start of main" << endl;

	cout << "end of main" << endl;
}
