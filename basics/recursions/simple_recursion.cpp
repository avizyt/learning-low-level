
#include <iostream>
int fibo(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1 || n == 2) {
    return 1;
  } else {
    return (fibo(n - 1) + fibo(n - 2));
  }
}

int main() {
  int n = 20;
  //   int val = fibo(10);
  for (int i = 0; i < n; ++i) {

    std::cout << i << "th Fibo = " << fibo(i) << "\n";
  }
  std::cout << n << "th Fibo = " << fibo(n) << "\n";
}