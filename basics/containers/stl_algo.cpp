

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template <typename Container> void displayData(Container arr) {
  for (auto item : arr) {
    std::cout << item << " ";
  }
  std::cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> data = {5, 2, 8, 9, 3, 7, 4, 6};
  displayData(data);

  sort(data.begin(), data.end());
  displayData(data);

  //   partial_sort(data.begin(), data.begin() + 3, data.end());
  //   displayData(data);

  bool found = std::binary_search(data.begin(), data.end(), 5);
  cout << found;

  // all even
  bool all_even =
      std::all_of(data.begin(), data.end(), [](int x) { return x % 2 == 0; });

  cout << all_even << "\n";

  int product =
      std::accumulate(data.begin(), data.end(), 1, std::multiplies<int>());
  cout << product;

  return 0;
}