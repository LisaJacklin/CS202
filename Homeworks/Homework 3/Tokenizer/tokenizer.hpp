#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

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

struct TokenAndPosition {
	string token;
	int line;
	unsigned int column;
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

#endif