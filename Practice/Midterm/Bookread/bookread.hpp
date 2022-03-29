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
using std::ostringstream;
using std::getline;

struct Token {
    string token;
    int paragraphs;
};

vector<string> lineToTokens(const string& line);
vector<Token> readLines(istream& is);
void printTokens(ostringstream& os, vector<Token>& tokens);

vector<Token> readLines(istream& is) {
    vector<Token> toRet;
    int Num = 0;
    string line;

    while (true) {
        getline(is, line);
        if (!is) {
            if (is.eof()) {
                //file is complete
                break;
            }
            //error....
            return toRet;
        }
        //process
        Num++;
        vector<string> tokens = lineToTokens(line);
        for (string s : tokens) {
            Token t;
            t.token = s;
            t.paragraphs = Num;
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


void printTokens(ostream& os, vector<Token>& tokens) {
    // vector<Token> tokens;
    for (Token t : tokens) {
       // os << t.token.length() << " "; //testing to make sure numbers are given
       // 
        //okay now, a wrapping function to make the words fit the correct requirements.
        int space_left = 50;
        if (t.token.length() < 50) {
           // os << t.token << " ";
            if (space_left > t.token.length() + 1) {
                os  << t.token << " ";
                space_left -= t.token.length();
            }
            if(space_left <= t.token.length()) {
                os << "\n" << t.token;
                space_left = 50;
            }
        }         
   } //this section won't work like i want it too because it's tokenizing in terms of individual strings rather than as a sentence or paragraph....
}
#endif
