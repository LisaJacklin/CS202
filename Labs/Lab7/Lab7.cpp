// Lab7.cpp 
// Lisa Jacklin
// CS 202
// 2/26/2022
//

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

/*
Requirements:
1. modify class (Probably use Vector3f) so the code compiles 
resonable.
code:
const Foo f;
cout << f << endl;
note that foo is the class name
2. operation should also print the value of data members in class

*/

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

    //using friend operator to print out the values of the class
    friend ostream& operator << (ostream& out, Vector3f a) {
        out << "[" << a.x << "," << a.y << "," << a.z << "]" << endl;
        return out;
    }
};

int main()
{
    cout << "start of main" << endl;

    //code given to print out 
    const Vector3f f;
    cout << f << endl;
    
    Vector3f a(3.1, 2.5, 7.4);
    cout << a << endl;

    cout << "end of main" << endl;
}

