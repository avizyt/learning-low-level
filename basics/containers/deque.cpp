#include <cstddef>
#include <deque>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  deque<int> dq = {1, 2, 3, 4, 5};

  dq.push_front(0);
  dq.push_back(6);

  // for (int x : dq) {
  //   std::cout << x << std::endl;
  // }

  cout << "Size of the deque: " << dq.size() << "\n";

  while (!dq.empty()) {
    cout << dq.back() << "\n";
    dq.pop_back();
  }

  cout << "Size of the deque: " << dq.size();

  return 0;
}