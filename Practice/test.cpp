#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "SmartArray.hpp"

int main()
{
  SmartArray<int> a(10);
  a[2] = 2;
  a[6] = 6;
  for (int i=0 ; i<a.size() ; i++ )
    cout << "a[" << i << "] = " << a[i] << endl;

  SmartArray<double> b(10);
  b[2] = 2.2;
  b[6] = 6.6;
  for (int i=0 ; i<b.size() ; i++ )
    cout << "b[" << i << "] = " << b[i] << endl;

  SmartArray<string> c(10);
  c[2] = "hello";
  c[6] = "world";
  for (int i=0 ; i<c.size() ; i++ )
    cout << "c[" << i << "] = " << c[i] << endl;

}
