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
	student s2{ 875, "wide reciever" , 1.2 };
	student s3{ 666, "say tan" , 4.0 };
	student s4{ 1, "old timer", 2.0 };

	//test-driven development (TDD)
	list < student> ll;
	REQUIRE(ll.size() == 0);

	//add a studnet
	ll.push_back(s1);
	REQUIRE(11.size() == 1);

	//verify s1 info is in that list
	auto s0 == ll.front(); //grabs the very first value of the list
	REQUIRE((s0.SID == s1.SID && s0.name == s1.name && s0.GPA == s1.GPA)); //test to make sure that the SID are the same

	//add all students
	ll.push_back(s2);
	ll.push_back(s3);
	ll.push_back(s4);
	REQUIRE(ll.size() == 4);

	//pop front element
	ll.push_front();
	REQUIRE(ll.size() == 3);

	//search for a studnet
	auto it = std::find_if(ll.begin(), ll.end(),
		[](const student& k) { return k.SID == 666}
};//use it for stl searches

REQUIRE(it != ll.end() );
REQUIRE(it->SID == 666); //remember -> is a pointer essentially

//print the list
for (auto s : ll) 
	cout << s.SID << " " << s.name << " " << s.GPA << endl;


//insert s1 in front of s3
ll.insert(it, s1);
cout << "------------" << endl;
for (auto s : ll) {
	cout << s.SID << " " << s.name << " " << s.GPA << endl;
	//TEST?????

	//test initializer vs. pushbacks
	list <student> students = { s2, s1, s3, s4 };
	REQUIRE(student.size() == 4);
	cout << "----------" << endl;
	for (auto s : ll)
		cout << s.SID << " " << s.name << " " << s.GPA << endl;
	//TEST??????????? is there a list1 == list 2 operator?
	//iterate thru each list (it1, it2) & check each element is equal

	//test sorting - add N items, call sort, & verify sorted
}

