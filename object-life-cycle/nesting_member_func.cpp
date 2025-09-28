#include <iostream>
using namespace std;

class Set {
  int m, n;

public:
  void input(void);
  void display(void);
  int largest(void);
};

int Set ::largest(void) {
  if (m >= n)
    return (m);
  else {
    return (n);
  }
}

void Set::input(void) {
  cout << "Input values of m and n" << "\n";
  cin >> m >> n;
}

void Set::display(void) { cout << "Largets value = " << largest() << "\n"; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Set A;
  A.input();
  A.display();

  return 0;
}