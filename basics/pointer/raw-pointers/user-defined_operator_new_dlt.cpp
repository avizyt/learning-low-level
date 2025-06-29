#include <cstddef>
#include <cstdlib>
#include <iostream>

int fLogMemory = 0;
int cBlockAllocated = 0;

// user defined operator new
void *operator new(size_t stAllocateBlock) {
  static int fInOpNew = 0; // gurad flag

  if (fLogMemory && !fInOpNew) {
    fInOpNew = 1;
    std::clog << "Memory block " << ++cBlockAllocated << " allocated for "
              << stAllocateBlock << " bytes\n";
    fInOpNew = 0;
  }
  return malloc(stAllocateBlock);
}

// user defined operator delete
void operator delete(void *pvMem) {
  static int fInOpDelete = 0;
  if (fLogMemory && !fInOpDelete) {
    fInOpDelete = 1;
    std::clog << "Memory block " << cBlockAllocated-- << " deallocated\n";
    fInOpDelete = 0;
  }
  free(pvMem);
}

int main(int argc, char *argv[]) {
  fLogMemory = 1;
  if (argc > 1)
    for (int i = 0; i < atoi(argv[1]); ++i) {
      char *pMem = new char[10];
      delete[] pMem;
    }
  fLogMemory = 0;
  return cBlockAllocated;
}