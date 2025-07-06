#include <iostream>
typedef long long ll;

// Tail-recursive fibo
// a holds F(i-2) and b holds F(i-1) in the current iteration

ll fibonacciTailRec(int n, ll a = 0, ll b = 1) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return b;
  }

  return fibonacciTailRec(n - 1, b, a + b);
}

int main() {
  int num;
  std::cout << "Enter a non-negative integer (n) to find the nth Fibo number "
               "(tail-recursive): ";
  std::cin >> num;

  if (num < 0) {
    std::cout << "Fibonacci numbers are not defined for negative indices."
              << std::endl;
  } else {
    std::cout << "The " << num
              << "th Fibonacci number is: " << fibonacciTailRec(num)
              << std::endl;
  }

  return 0;
}