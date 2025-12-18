
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

void hw() { std::cout << "Hello Concurrent World\n"; }

void add(std::vector<int> arr) {
  int sum = 0;
  for (int i = 0; i < arr.size(); ++i) {
    sum += arr[i];
  }
}

int main() {

  std::thread t(add);
  t.join();

  return 0;
}