#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  const char *c1 = "hello";
  auto x = &c1;

  std::cout << *x << ", Good Morning!" << std::endl;

  std::cout << "c1: " << &c1 << std::endl;
  //   std::cout << "Address of c1: " << c1_ads << std::endl;
  return 0;
}