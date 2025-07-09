#include "../utils.h"
#include <iostream>

int main() {
  int n = 10;

  ll x = 1;
  vll arr = {};
  REP(i, 0, n) { arr.push_back(x); }
  REP(i, 0, n) { std::cout << arr[i] << std::endl; }
}