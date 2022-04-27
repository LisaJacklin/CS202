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
    int columns; //trying to add columns as a factor in printTokens...

public:
    //read lines and paragraph to tokens should be fine for multicolumns.
    void readLines(vector<Token>& toRet, istream& is)  {
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
    void paragraphsToTokens(vector<string>& toRet, const string& line)  {
        //vector<string> toRet; this is now included in the void
        istringstream is(line);
        string token;

        while (true) {
            is >> token;
            if (!is) { //eof checker
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

    //print tokens is where columns can be adjusted!
    void printTokens(ostream& os, vector<Token>& tokens, int & columns) {
       
     int space_left = (80 - 2*columns )/ columns; //this should be 80 total characters per line,
     //with columns * 2 spaces of separation, which is separated by columns

        for (int i = 0; i < token.size(); i++) {
            if (token[i].size() < 38) {
                if (space_left > token[i].size() + 1) {
                    os << token[i] << " ";
                    space_left = space_left - token[i].size();
                }
            } 
            if (token[i].size() == 38) {
                os << "    " << token[i]; //space of 4
            }
            if (token[i].size() > 38 && token[i].size() < 80) {
                os << token[i + 4] << " "; //print the 4th paragraph in the second column top
            }
            if (token[i + 4].size() == 80) {
                os << "\n\n" << " "; //new lines first column to second column again
            }



#if 0 //code from book.hpp used as reference
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
#endif
        }
    }
};


#endif