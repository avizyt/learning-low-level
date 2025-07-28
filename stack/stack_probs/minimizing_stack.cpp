#include <algorithm>
#include <iostream>
#include <vector>

int minimizeStack(std::vector<int> ls) {
  int stack_size = 0;
  for (int num : ls) {
    stack_size = std::max(stack_size, num);
  }
  return stack_size;
}

int main() {
  std::cout << "Minizing Stack" << "\n";
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << minimizeStack(arr);
}