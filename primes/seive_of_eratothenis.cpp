
#include <iostream>
#include <vector>

void findPrimes(int n) {
  std::vector<bool> isPrime(n + 1, true);

  isPrime[0] = isPrime[1] = false;

  for (int p = 2; p * p < n; p++) {
    if (isPrime[p]) {
      for (int i = p * p; i <= n; i += p)
        isPrime[i] = false;
    }
  }

  std::cout << "Prime number up to " << n << ": " << "\n";
  for (int p = 2; p <= n; p++) {
    if (isPrime[p]) {
      std::cout << p << " ";
    }
  }
  std::cout << std::endl;
}

int main() {
  int limit = 100;
  findPrimes(limit);
}