//testll.cpp
//Lisa Jacklin
//CS 202
// 3/22 /2022

//in class testclass code

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <list>
using std::list;

struct student {
	int SID;
	string name;
	double GPA;
	// ...
};

TEST_CASE("QUEUE TEST", "{Queue}") {
	//LL allows push_front, push_back, pop_front, pop_back
	//queue only allows push_back, pop_front
	//stack only allows push_front, pop_front

	//create a few students
	student s1{ 115, "Bill fold", 3.2 };
	student s2{875, "wide reciever" , 1.2};
	student s3{666, "say tan" , 4.0};
	student s4{1, "old timer", 2.0};

	//test-driven development (TDD)
	list < student> 11;
	REQUIRE(11.size() == 0);

	//add a studnet
	11.push_back(s1);
	REQUIRE(11.size() == 1);

	//verify s1 info is in that list
	auto s0 == 11.front(); //grabs the very first value of the list
	REQUIRE(s0.SID == s1.SID); //test to make sure that the SID are the same
}

