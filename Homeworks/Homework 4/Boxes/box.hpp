#ifndef BOX_HPP
#define BOX_HPP

//Box.cpp
// Lisa Jacklin
// CS 202 Homework 4
// 4/5/2022
//

/*
* Requirements:
* - write a set of classes representing boxes (which can be displayed)
* - include width and height and can be printed to screen or file
* - boxes can be hollow, filled or checkered...
*
* Abstract base called Box,
* Derived: filledBox, HollowBox, and CheckeredBox
*
*/

#include <iostream>
#include <string>

using std::ostream;
using std::string;
using std::make_unique;

//abstract base class Box
class Box {
public:
    Box(int w, int h) : width(w), height(h) { }

     ~Box() { }
     //does this need to be virtual?

     //accessor functions
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    //mutator functions
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h;}

    //now virtual functions... these need to be defined by 
    //by each derived class
    virtual void print(ostream& os) const = 0;
    virtual string type() const = 0;

private:
    int width;
    int height;
};

//derived classes
class FilledBox : public Box {
public:
    FilledBox(int w, int h) : Box(w, h) { }
    FilledBox() : Box(1, 1) { }

    void print(ostream& os) const {
        for (int i = 0; i < getHeight(); i++) {
            for (int j = 0; j < getWidth(); j++) {
                os << "x"; // prints x for all values of the box
            }
            os << "\n";
        }
    }

    string type() const { return "Filled"; }
};
class HollowBox : public Box {
public:
    HollowBox(int w, int h) : Box(w, h) { }
    HollowBox() : Box(1, 1) {}

    void print(ostream& os) const {
        for (int i = 0; i < getWidth(); i++) os << "x";
        os << "\n";
        //the 2 accounts for the outline of the box
        // and allows an x to be placed just before the space and 
        //at the very beginning of the set.
        for (int i = 0; i < getHeight() - 2; i++) {
            os << "x";
            for (int i = 0; i < getWidth() - 2; i++) os << " ";
            os << "x\n";
        }
        
        if (getHeight() > 1) {
            for (int i = 0; i < getWidth(); i++) os << "x";
            os << "\n";
        }
    }

    string type() const { return "Hollow"; }
};
class CheckeredBox : public Box {
public:
    CheckeredBox(int w, int h) : Box(w, h) {}
    CheckeredBox() : Box(1, 1) { }

    void print(ostream& os) const {
        for (int i = 0; i < getHeight(); i++) {
            for (int j = 0; j < getWidth(); j++) {
                if (j % 2 == i % 2) os << "x";
                //every other prints an x and then a space
                //this alternates between each row.
                else os << " ";
            }
            os << "\n";
        }
    }

    string type() const {return "Checkered";}
};

//ostream overloading operator
//print function now complete
ostream& operator<<(ostream& os, const Box& b) {
    b.print(os);
    return os;
}

//now box factor pointer...
std::unique_ptr<Box> boxFactory(char c, int w, int h) {
    if (c == 'f') { //f is for filled
        return make_unique<FilledBox>(FilledBox(w, h));
    }

    if (c == 'h') { //h is for hollow
        return make_unique<HollowBox>(HollowBox(w, h));
    }

    if (c == 'c') {// and c is for checkered
        return make_unique<CheckeredBox>(CheckeredBox(w, h));
    }
    return nullptr;
}

#endif