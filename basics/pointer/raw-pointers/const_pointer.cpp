#include <iostream>
struct X {
  X(int i) : m_i(i) {}
  int m_i;
};

int main() {
  const X cx(10);
  const X *pcx = &cx;
  const **ppcx = &pcx;
}