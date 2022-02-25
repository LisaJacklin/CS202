/*

#include "catch.hpp"

class Vector3f {
public:

    float x;
    float y;
    float z;

    Vector3f() : x(0), y(0), z(0) {
    }

    Vector3f(float one, float two, float three) : x(one), y(two), z(three) {

    }

    Vector3f(const Vector3f& orig) {
        x = orig.x;
        y = orig.y;
        z = orig.z;
    }


};

bool operator==(const Vector3f& a, const Vector3f& b) {
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

bool operator!=(const Vector3f& a, const Vector3f& b) {
    return (a.x != b.x) && (a.y != b.y) && (a.z != b.z);
}

TEST_CASE("Vector3f tests", "[vector3f]") {
    Vector3f data;

    Vector3f setData(6.5, 7.1, 8.2);

    Vector3f copy1(1.2, 3.1, 6.4);
    Vector3f copy2(copy1);

    REQUIRE(data.x == 0);
    REQUIRE(data.y == 0);
    REQUIRE(data.z == 0);

    REQUIRE(setData.x == Approx(6.5));
    REQUIRE(setData.y == Approx(7.1));
    REQUIRE(setData.z == Approx(8.2));

    REQUIRE(copy2.x == Approx(1.2));
    REQUIRE(copy2.y == Approx(3.1));
    REQUIRE(copy2.z == Approx(6.4));

    REQUIRE(data != setData);
    REQUIRE(copy2 == copy1);

};

*/