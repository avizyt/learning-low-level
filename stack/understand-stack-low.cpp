#include <iostream>
using namespace std;

void bar(int x) {
  int z = x + 10;
  std::cout << "z = " << z << std::endl;
}

void foo() {
  int y = 20;
  bar(y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  foo();

  return 0;
}