#include <iostream>
int main() {
  unsigned int num = 12345;
  //   getting number of bits
  int count = __builtin_popcount(num);
  //   unsigned bits = 0;
  //   for (; num; ++bits) {
  //     num &= num - 1;
  //   }
  //   std::cout << bits << "\n";
  std::cout << count;
}