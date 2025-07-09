#include "../../../utlis/utils.h"
#include <iostream>
#include <type_traits>

template <unsigned int n> struct factorial {
  enum { value = n * factorial<n - 1>::value };
};

template <> struct factorial<0> {
  enum { value = 1 };
};

// using integral constant

template <ll n>
struct advFactorial
    : std::integral_constant<ll, n * advFactorial<n - 1>::value> {};

template <> struct advFactorial<0> : std::integral_constant<ll, 1> {};

// using constexpr
constexpr ll constExprfactorial(ll n) {
  return (n == 0) ? 1 : n * constExprfactorial(n - 1);
}

// int main() { std::cout << factorial<7>::value << "\n"; }
// int main() { std::cout << advFactorial<7>::value << "\n"; }
int main() {
  //   char test[conatExprfactorial(3)];
  std::cout << constExprfactorial(7) << "\n";
}
