#ifndef BOOKREAD_HPP
#define BOOKREAD_HPP

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

//vector<string> lineToTokens(const string& line);
vector<Token> readLines(istream& is);
void printTokens(ostream& os, const vector<Token>& tokens);

vector <string> paragraphs(const string& text);

vector<Token> readLines(istream& is) {
    vector<Token> toread;
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
            return toread;
        }

        //process
        lineNum++;
        vector<string> tokens = paragraphs(line);
        for (string s : tokens) {
            Token t;
            t.token = s;
            toread.push_back(t);
        }
    }
    return toread;

}

#if 0
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
#endif
void printTokens(ostream& os, const vector<Token>& tokens) {
    for (Token t : tokens) {
        
        os << t.token << " ";
        //attempting to use this to separate values into about 50 character sections...
       
    }
}

vector <string > paragraphs(const string& text) {
    vector<string> toread;

    istringstream is(text);
    string token;

    while (true) {
        is >> token;
        if (!is) {
            if (is.eof()) {
                break;
            }
            return toread;
        }

        toread.push_back(token);
    }

    return toread;
}

#endif
