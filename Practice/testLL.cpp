#define CATCH_CONFIG_MAIN
#include "Catch/catch.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <list>
using std::list;

struct Student {
  int SID;
  string name;
  double GPA;
  // ...
};

TEST_CASE("Queue Test", "[Queue]") {

  // LL allows push_front, push_back, pop_front, pop_back
  // Queue only allows push_back, pop_front
  // Stack only allows push_front, pop_front

  // create a few students
  Student s1 { 115, "Bill Fold", 3.2 };
  Student s2 { 785, "Wide Receiver", 1.2 };
  Student s3 { 666, "Say Tan", 4.0 };
  Student s4 {   1, "Old Timer", 2.0 };

  // Test-driven development (TDD)
  list<Student> ll;
  REQUIRE(ll.size() == 0);

  // add a student
  ll.push_back(s1);
  REQUIRE(ll.size() == 1);

  // verify s1 info is in that list
  auto s0 = ll.front();
  REQUIRE((s0.SID==s1.SID && s0.name==s1.name && s0.GPA==s1.GPA));

  // add all students
  ll.push_back(s2);
  ll.push_back(s3);
  ll.push_back(s4);
  REQUIRE(ll.size() == 4);

  // pop front element
  ll.pop_front();
  REQUIRE(ll.size() == 3);

  // search for a Student
  auto it=std::find_if( ll.begin(), ll.end(),
               [](const Student & k) { return k.SID==666; } );
  REQUIRE( it != ll.end() );
  REQUIRE( it->SID == 666 );

  // print the list
  for ( auto s : ll )
    cout << s.SID << " " << s.name << " " << s.GPA << endl;
  // insert s1 in front of s3
  ll.insert(it, s1);
  cout << "-------" << endl;
  for ( auto s : ll )
    cout << s.SID << " " << s.name << " " << s.GPA << endl;
  // TEST????

  // test initializer vs. pushbacks
  list<Student> students = { s2, s1, s3, s4 };
  REQUIRE(students.size() == 4);
  cout << "-------" << endl;
  for ( auto s : ll )
    cout << s.SID << " " << s.name << " " << s.GPA << endl;
  // TEST???? is there a list1 == list2 operator?
  // iterate thru each list (it1, it2) & check each element is equal

  // test sorting - add N items, call sort, & verify sorted
  // e.g. 8,5,3,1,9, sort, then verify 1,3,5,8,9
  // will catch if sort returned 1,2,3,4,5

  // test sorting - add 1000 random numbers, sort, verify
  // e.g. SID of ith is <= SID of i+1th value

  // add 1,000,000 (1,000,000 down to 1)
  // after sorting, ith should be i

}

