#include <iostream>
#include <vector>
int main() {
  std::vector<int> arr = {4, 5, 6, 9, 12, 16, 18, 32, 256};

  for (int n : arr) {
    // true: 1
    // false: 0
    std::cout << (n && !(n & (n - 1)) ? 1 : 0) << " ";
  }
  std::cout << "\n";
  std::cout << "===========================" << "\n";
  std::cout << (5 & 4) << "\n";
  std::cout << (5 & 0) << "\n";
  std::cout << (5 & 1) << "\n";
}