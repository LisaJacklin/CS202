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
#define CATCH_CONFIG_MAIN
#include "catch.hpp" //has to be included to test

#include <iostream>
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


TEST_CASE("Vector3f tests", "[Vector3f]") {
   //this should be the default constructor
    Vector3f data;
    //user inputer constructor
    Vector3f userData(3.1, 4.1, 5.9);
    //copy constructor
    Vector3f copy(1.2, 3.4, 5.6);
    Vector3f copy2(copy);

    //this tests the default constructor which sets vals to zero
    REQUIRE(data.x == 0);
    REQUIRE(data.y == 0);
    REQUIRE(data.z == 0);

    //test the user input constructors data
    //note approx added to prevent failed test
    REQUIRE(userData.x == Approx(3.1));
    REQUIRE(userData.y == Approx(4.1));
    REQUIRE(userData.z == Approx(5.9));

    //now testing the copy constructor
    REQUIRE(copy2.x ==Approx( 1.2));
    REQUIRE(copy2.y == Approx(3.4));
    REQUIRE(copy2.z ==Approx( 5.6));

    //make sure data is correct
    REQUIRE(data != userData);
    REQUIRE(copy2 == copy);

}