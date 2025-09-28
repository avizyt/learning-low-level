#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <vector>

using namespace std;

template <typename Container> void displayElements(const Container &c) {
  for (auto it = begin(c); it != end(c); ++it) {
    cout << *it << " ";
  }
  cout << "\n";
}

template <typename Container>
void print(const Container &c, ostream &out = cout) {
  if (c.empty()) {
    out << "(empty)";
  } else {
    auto itr = begin(c);

    out << "[ " << *itr++;

    while (itr != end(c)) {
      out << ", " << *itr++;
    }
    out << " ]" << endl;
  }
}

int main() {
  std::vector<int> arr = {5, 3, 5, 2, 6};
  std::list<int> l = {1, 2, 3, 4, 5};
  array<int, 5> x = {10, 12, 13, 14, 15};

  print(x);
  cout << x.size() << "\n";
}
