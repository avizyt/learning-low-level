
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
class Blanks {
public:
  Blanks() {}
  void *operator new(size_t stAllocateBlock, char chInit);
};

void *Blanks::operator new(size_t stAllocateBlock, char chInit) {
  void *pvTemp = malloc(stAllocateBlock);
  if (pvTemp != 0) {
    memset(pvTemp, chInit, stAllocateBlock);
  }
  return pvTemp;
}

int main() {
  Blanks *a5 = new (0xa5) Blanks;

  std::cout << a5;
  return a5 != 0;
}