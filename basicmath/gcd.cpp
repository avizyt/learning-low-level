
#include <iostream>

int gcd01(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// GCD using Euclid algorithm
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

// LCM using GCD
long long lcm(int a, int b) {
  return (static_cast<long long>(a) * b) / gcd(a, b);
}

int main() {
  int a, b;
  a = 48;
  b = 18;
  std::cout << "GCD: " << gcd(a, b) << "\n";

  std::cout << "GCD: " << lcm(a, b);
}