#include <iostream>
using namespace std;

class Item {
  int number;
  float cost;
  float add() { return number + cost; }

public:
  void getdata(int a, float b);
  float total() { return add(); };
  void putdata(void);
};

// member function definition
void Item ::getdata(int a, float b) {
  number = a;
  cost = b;
}
void Item ::putdata(void) {
  cout << number;
  cout << endl;
  cout << cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Item it;

  it.getdata(2, 3.0);
  it.putdata();
  cout << "\n" << it.total();
}