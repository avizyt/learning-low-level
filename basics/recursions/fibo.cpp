#include <iostream>
#include <vector>

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
  // 1. Base Cases:
  if (n == 0) {
    return 0; // F(0) = 0
  } else if (n == 1) {
    return 1; // F(1) = 1
  }
  // 2. Recursive Step: F(n) = F(n-1) + F(n-2)
  else {
    return fibonacci(n - 1) + fibonacci(n - 2); // Two recursive calls!
  }
}

long long fibonacciIterative(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  long long a = 0;      // for F(i-2)
  long long b = 1;      // for F(i-1)
  long long result = 0; // for F(i)

  // loop from 2 up to n
  for (int i = 2; i <= n; ++i) {
    result = a + b; // current fib is sum of prev two
    a = b;          // Update a to b ethe prev b
    b = result;     // Update b to be the current result
  }
  return result;
}

// Memoization
const int MAX_N = 100;
std::vector<long long> memo(MAX_N + 1, -1);

long long fiboMemoized(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (memo[n] != -1) {
    return memo[n];
  }

  // if not computed calculate it, stire it, and then return it
  memo[n] = fiboMemoized(n - 1) + fiboMemoized(n - 2);

  return memo[n];
}

int main() {
  int num;
  std::cout
      << "Enter a non-negative integer (n) to find the nth Fibonacci number: ";
  std::cin >> num;

  if (num < 0) {
    std::cout << "Fibonacci numbers are not defined for negative indices."
              << std::endl;
  } else {
    // std::cout << "The " << num << "th Fibonacci number is: " <<
    // fibonacci(num)
    //   << std::endl;
    std::cout << "The " << num
              << "th Fibonacci number is: " << fiboMemoized(num) << std::endl;
  }

  return 0;
}