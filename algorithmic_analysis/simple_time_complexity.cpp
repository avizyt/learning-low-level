#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void logarithm(int n) {
  int i = 1;
  while (i >= 1) {
    i = i / 2;
    cout << i << "\n";
  }
}

void log_of_k(int n) {
  float log_k = 0.0;
  for (int i = 0; i <= n; ++i) {
    log_k = log_k + log10(i);
  }
  cout << log_k << "\n";
  cout << n * log10(n);
}

void func1(int n) {
  int i = 1, s = 1;
  while (s < 20) {
    i += 1;
    s = s + i;
    cout << s << "\n";
  }
}

int main() {
  vector<int> squares(100);

  for (int i = 0; i < squares.size(); ++i) {
    squares[i] = i * i;
  }

  for (int i = 0; i < squares.size(); ++i) {
    cout << i << " " << squares[i] << endl;
  }

  return 0;
}
