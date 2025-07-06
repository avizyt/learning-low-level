
#include <iostream>
typedef long long ll;

ll factorial(int n) {
  // 1. Base Case: If n is 0 or 1, return 1
  if (n == 0 || n == 1) {
    return 1;
  }
  // Recursive step: n! = n * (n-1)
  else {
    return n * factorial(n - 1);
  }
}

int main() {
  int num;
  std::cout << "Enter a non-negative integer: ";
  std::cin >> num;

  if (num < 0) {
    std::cout << "Factorial is not defined for negative numbers." << std::endl;
  } else {
    std::cout << "Factorial of " << num << " is: " << factorial(num)
              << std::endl;
  }

  return 0;
}