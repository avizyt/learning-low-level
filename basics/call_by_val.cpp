
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int x = 5, y = 6;
  void change(int, int);
  cout << "X: " << x << " and " << "Y: " << y << "\n";
  change(x, y);
  cout << "\n";
  cout << "X: " << x << " and " << "Y: " << y << "\n";
  return 0;
}

void change(int a, int b) {
  a = a + 5;
  b = b + 5;
  cout << "X: " << a << " and " << "Y: " << b;
}