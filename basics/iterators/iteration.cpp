#include <forward_list>
#include <iostream>
#include <list>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  forward_list<int> flist = {10, 20, 30, 40, 50};

  for (auto it = flist.begin(); it != flist.end(); ++it) {
    cout << *it << " ";
  }

  for (auto it = flist.begin(); it != flist.end(); ++it) {
    (*it)++;
  }

  cout << endl;
  for (auto it = flist.begin(); it != flist.end(); ++it) {
    cout << *it << " ";
  }

  // bidirectional iterator

  list<int> numbers = {11, 12, 13, 14, 15, 16};

  cout << "Traversing the list forwards:\n";

  for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
    cout << *it << " ";
  }

  cout << endl;
  for (list<int>::reverse_iterator rit = numbers.rbegin();
       rit != numbers.rend(); ++rit) {
    cout << *rit << " ";
  }

  return 0;
}