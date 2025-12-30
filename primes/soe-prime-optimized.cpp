
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// standard sieve to get Primes up to sqrt(N)

void getbasePrime(int limit, vector<int> &primes) {
  vector<bool> mark(limit + 1, true);
  for (int p = 2; p * p <= limit; p++) {
    if (mark[p]) {
      for (int i = p * p; i <= limit; i += p) {
        mark[i] = false;
      }
    }
  }
  for (int p = 2; p <= limit; p++) {
    if (mark[p])
      primes.push_back(p);
  }
}

void segmentedSieve(long long n) {
  int limit = floor(sqrt(n) + 1);
  vector<int> primes;
  getbasePrime(limit, primes);

  long long low = limit;
  long long high = 2 * limit;

  for (int p : primes) {
    if (p <= n)
      cout << p << " ";
  }

  // process segment one by one
  while (low <= n) {
    if (high > n)
      high = n;

    vector<bool> mark(high - low + 1, true);

    for (int i = 0; i < primes.size(); i++) {
      long long startNode = (low / primes[i]) * primes[i];
      if (startNode < low)
        startNode += primes[i];

      for (long long j = startNode; j <= high; j += primes[i]) {
        mark[j - low] = false;
      }

      for (long long i = low; i <= high; i++) {
        if (mark[i - low])
          cout << i << " ";
      }
      low = low + limit;
      high = high + limit;
    }
    cout << endl;
  }
}

int main() {
  long long n = 1000000000;
  cout << "Prime up to " << n << ":" << endl;
  segmentedSieve(n);
  return 0;
}