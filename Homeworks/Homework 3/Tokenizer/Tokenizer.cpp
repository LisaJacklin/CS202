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

*/

#include <iostream>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

struct TokenAndPosition {
	string _token;
	int _line;
	unsigned int _column;
};
vector<string> lineToTokens(const string& line);
vector<TokenAndPosition> readLines(std::istream& is);
void printTokens(std::ostream& os, const vector<TokenAndPosition>& tokens);

int main()
{
	cout << "start of main" << endl;

	cout << "end of main" << endl;
}
