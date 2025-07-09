#include <iostream>
template <typename T> T rightmostSetBitRemoved(T n) { return n & (n - 1); }

int main() { std::cout << rightmostSetBitRemoved(100) << "\n"; }