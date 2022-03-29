#ifndef BOOK_HPP
#define BOOK_HPP

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

class Token {
private:
    vector<string> token;
    vector<int> paragraphs;

public:
    void readLines(vector<Token>& toRet, istream& is) {
        // vector<Token> toRet;
        vector<int> paragraph;

        //int paragraph = 0;
        string token;

        while (true) {
            getline(is, token);
            if (!is) {
                if (is.eof()) {
                    //file is complete
                    break;
                }
                //error....
                //return toRet;
            }
            //trying this, to see if they can 
            while (token.length() == 0) {
                //process
          // paragraph++;
                vector<string> tokens;
                paragraphsToTokens(tokens, token);
                for (string s : tokens) {
                    Token t;
                    toRet.push_back(t);
                }
            }
        }
        //return toRet;

    }

    void paragraphsToTokens(vector<string>& toRet, const string& line) {
        //vector<string> toRet;
        istringstream is(line);
        string token;

        while (true) {
            is >> token;
            if (!is) {
                if (is.eof()) {
                    break;
                }
                //Broken, but not much we can do
                //return toRet;
            }
            while (token.length() == 0) {
                toRet.push_back(token); //added so it should wait till full paragraph...
            }
        }
        // return toRet;
    }

    void printTokens(ostream& os, vector<Token>& tokens) {

        for (int i = 0; i < token.size(); i++) {
            // os << token[i] << " ";
              //okay now, a wrapping function to make the words fit the correct requirements....
            int space_left = 50;
            // os << t.token.length() << " "; //testing to make sure numbers are given
            if (token[i].size() < 50) {
                // os << t.token << " ";
                if (space_left > token[i].size() + 1) {
                    os << token[i] << " ";
                    space_left -= token[i].size();
                }
                if (space_left <= token[i].size()) {
                    os << "\n\n";
                    space_left = 50;
                }
            }
        }
    }
};


#endif