
#include <iostream>
#include <vector>

std::vector<int> subset;
int n = 5;

void search(int k) {
  if (k == n + 1) {

  } else {
    subset.push_back(k);
    search(k + 1);
    subset.pop_back();
    search(k + 1);
  }
}

int main() {
  search(5);
  for (int i = 0; i <= n; ++i) {
    std::cout << subset[i] << " ";
  }
}