
#include <iostream>
using namespace std;

int main() {

  int *p, x;
  x = 10;
  p = &x;

  cout << "The address of x(through POINTER) is " << &p << "\n";
  cout << "The value of x(through POINTER) is " << *p << "\n";
  cout << "The value of x is: " << x;

  return 0;
}