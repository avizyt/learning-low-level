#include <iostream>
#include <ostream>
#include <string>

class MyClass {
public:
  int num;
  std::string name;
  void print() { std::cout << name << ":" << num << std::endl; }
};

void func_A(MyClass *mc) { mc->num = 3; }

void func_B(MyClass mc) {
  mc.num = 21;
  std::cout << "Local copy of mc:";
  mc.print();
}

int main() {

  MyClass *pmc = new MyClass{108, "Nick"};

  // print the memory address
  std::cout << pmc << "\n";

  // copy the pointed-to object by referencing the pointer to access the
  // contenct of he memory location mc is a separatoe objcet, allocated here on
  // the stack.
  MyClass mc = *pmc;

  MyClass *pcopy = &mc;

  pmc->print();

  MyClass *pmc2 = pmc;

  pmc2->name = "Erica";
  pmc->print();
  pmc2->print();

  // pass the pointer to a function.
  func_A(pmc);
  pmc->print();
  pmc2->print();

  // dereferencing the pointer and pass a copy
  // of the pointed-to object to a function
  func_B(*pmc);
  pmc->print();
  delete (pmc);
}