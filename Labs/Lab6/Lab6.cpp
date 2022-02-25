// Lab6.cpp
//Lisa Jacklin
//CS 202
//2/23/2022

/*
Requirements:
part 1:
create blank class Bector3f 
- containing float members x, y , z
-add bool operators to test equality and inequality

Write a test that checks:
- default constructor sets members  to zero
- user constructor allows values to be set to some val.
- copy constructor copies members to each other
- euqality/inequality operators work

*/

#include <iostream>
#include "catch.hpp" //has to be included to test
using std::cout;
using std::endl;

class Vector3f { 
public:
    //float memebers
    //note these members are not private because of the bool operators
    float x, y, z;

    // default constructor sets members  to zero
    Vector3f() : x(0.0), y(0.0), z(0.0) {
        cout << "default constructor" << endl;
    };

    // user constructor allows values to be set to some val.
    Vector3f(float one, float two, float three) : x(one), y(two), z(three) {
        cout << "(f, f, f) constructor" << endl;
    };

    //copy constructor copies members to each other
    Vector3f(const Vector3f& original) {
        x = original.x;
        y = original.y;
        z = original.z;

        cout << "copy constructor" << endl;
    }

    ~Vector3f() {
        cout << "deconstructor" << endl;
    }
};

//bool operators
bool operator==(const Vector3f& a, const Vector3f& b) {
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

bool operator!=(const Vector3f& a, const Vector3f& b) {
    return (a.x != b.x) && (a.y != b.y) && (a.z != b.z);
}

int main()
{
    cout << "start of main" << endl;

    Vector3f a(2.0, 4.0, 5.0);
    cout << a << endl;

    Vector3f b(5.0);
    cout << b << endl;


    cout << "end of main" << endl;
}
