#include <iostream>
using std::cout;
using std::endl;

// ***** this can vary based on computer and operating system *****

int global_var = 1;

void fcn3() {
  int i;
  cout << "fcn3::i address = " << &i << endl;
}
void fcn2() {
  int i;
  cout << "fcn2::i address = " << &i << endl;
  fcn3();
}
void fcn1() {
  int i;
  cout << "fcn1::i address = " << &i << endl;
  fcn2();
}

int main()
{
  int stack_var = 2;

  int * heap_var = new int[1000];  // new int is allocated in the heap
//  *heap_var = 3;

  cout << "global_var address = " << &global_var << endl;
  cout << "heap_var address = " << heap_var << endl;
  cout << "&heap_var address = " << &heap_var << endl;
  cout << "stack_var address = " << &stack_var << endl;

  fcn1();

}

