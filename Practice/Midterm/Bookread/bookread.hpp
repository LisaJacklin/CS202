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

class Token {
private:
    vector<string> token;
    vector<int> line;
    vector<int> column;
public:

    friend ostream& operator<< (ostream& out, vector<Token>& a);

    vector <string > paragraphs(const string& line) {
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

    vector<string> readLines(istream& is) {
        vector<string> toread;
        int lineNum = 0;
        string paragraph;

        while (true) {

            getline(is, paragraph);
            if (getline(is, paragraph)) {
                // line contains one line from the input stream
                toread.push_back(paragraph);
            }
            else {
                // inputStream is empty, EOF or in error state
                break;
            }

            //test case
            if (!is) {
                if (is.eof()) {
                    //good, we're done
                    break;
                }
                //bad error
                return toread;
            }
        }
        return toread;
    }

    //void printTokens(ostream& os, vector<Token> & tokens) {
    //   // vector<Token> tokens;
    //    
    //    for (Token t : tokens) {
    //        
    //        os << t.token << " ";
    //        //attempting to use this to separate values into about 50 character sections...

    //    }
    //}
};

ostream& operator<< (ostream& out, vector<Token>& a) {
    out << a << " ";
    return out;
}

#endif
