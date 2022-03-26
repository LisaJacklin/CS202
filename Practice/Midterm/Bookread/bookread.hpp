#ifndef BOOKREAD_HPP
#define BOOKREAD_HPP

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

//changed from a struct to a class
class TokenAndPosition {
	vector <string> token;
	vector <int> line;
	vector <unsigned int> column;

public: 

private: 
};

//function and vector declarations

//vector<string> lineToTokens(const string& line); now in class
//vector<TokenAndPosition> readLines(istream& is); now in class

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
	int lineNumber = 0; //starts at line zero
	string line; //and is given a string value

	while (true) {
		getline(is, line); //pulls the stream and the line
		if (!is) {
			if (is.eof()) {
				//were have finished reading the files
				break;
			}
			//something went wrong...
			return readMe;
		}

		//now to read the lines if no errors and eof occur
		lineNumber++;
		//this calls to another vector that is built above
		vector<string> tokens = linestoTokens(line);
		for (string s : tokens) {
			//now, using code from linestotokens,
			TokenAndPosition t;
			t.token = s;
			t.line = lineNumber;
			t.column = line.find(t.token);
			readMe.push_back(t);
		}
	}
}

void printTokens(ostream& os, const vector<TokenAndPosition>& tokens) {
	for (TokenAndPosition t : tokens) { // for each token
		//the ostream prints a line
		os << "line " << t.line << ", Column " << t.column << " : \ " << t.token
			<< " \ " << endl;
	}
}

#endif