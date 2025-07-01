#include "stack.h"
#include <iostream>

void displayStack(bool success, Stack<short> &stack);
void checkState(Stack<short> &stack);

int main() {
  Stack<short> shortStack(10);
  short num;
  bool success;

  checkState(shortStack);

  for (int i = 0; i < 10; ++i) {
    num = 10 * (i + 1);
    success = shortStack.push(num);
    if (success) {
      std::cout << "pushed: " << num << "\n";
    }
    displayStack(success, shortStack);
  }

  for (int i = 0; i < 10; ++i) {
    success = shortStack.pop(num);
    if (success) {
      std::cout << "popped: " << num << "\n";
    }
    displayStack(success, shortStack);
  }
  return 0;
}

void displayStack(bool success, Stack<short> &stack) {
  short num;
  int numVal;

  if (success) {
    numVal = stack.getNumValues();
    stack.peek(num);

    if (numVal > 0)
      std::cout << "numValues: " << numVal << "\tpeeked: " << num << std::endl;
    else
      std::cout << "numValues: " << numVal << std::endl;
  }

  checkState(stack);
}
void checkState(Stack<short> &stack) {
  if (stack.isFull())
    std::cerr << "\nstack is full\n\n";
  else if (stack.isEmpty())
    std::cerr << "\nstack is empty\n\n";
}