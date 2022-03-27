#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <sstream>

using std::ostream;
using std::istream;
using std::string;
using std::find;
using std::vector;
using std::istringstream;
using std::getline;

struct Token {
    string token;
    int line;
    int column;
};

vector<string> lineToTokens(const string& line);
vector<Token> readLines(istream& is);
void printTokens(ostream& os, const vector<Token>& tokens);

vector<Token> readLines(istream& is) {

    vector<Token> toRet;
    int lineNum = 0;
    string line;

    while (true) {

        getline(is, line);
        if (!is) {
            if (is.eof()) {
                //good, we're done
                break;
            }
            //bad error
            return toRet;
        }

        //process
        lineNum++;
        vector<string> tokens = lineToTokens(line);
        for (string s : tokens) {
            Token t;
            t.token = s;
            t.line = lineNum;
            t.column = line.find(t.token);
            toRet.push_back(t);
        }

    }

    return toRet;

}

vector<string> lineToTokens(const string& line) {
    vector<string> toRet;

    istringstream is(line);
    string token;

    while (true) {
        is >> token;
        if (!is) {
            if (is.eof()) {
                break;
            }
            //Broken, but not much we can do
            return toRet;
        }

        toRet.push_back(token);
    }

    return toRet;
}

void printTokens(ostream& os, const vector<Token>& tokens) {
    for (Token t : tokens) {
        os << "Line " << t.line << ", Column " << t.column << ": \"" << t.token << "\"" << std::endl;
    }
}

#endif
