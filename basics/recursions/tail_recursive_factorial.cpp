#include <iostream>
typedef long long ll;

ll factorialTailRecursive(int n, ll acc = 1) {
  if (n == 0 || n == 1) {
    return acc;
  }

  return factorialTailRecursive(n - 1, n * acc);
}

int main() {
  int num;
  std::cout << "Enter a non-negative integer for factorial (tail-recursive): ";
  std::cin >> num;

  if (num < 0) {
    std::cout << "Factorial is not defined for negative numbers." << std::endl;
  } else {
    std::cout << "Factorial of " << num
              << " is: " << factorialTailRecursive(num) << std::endl;
  }

  return 0;
}