
#include <iostream>
#include <string>

// Recursive function to reverse a string in-place using indices
void reverseStringInPlaceRecursive(std::string &s, int left, int right) {
  // Base Case: In left pointer crosses or meets right pointer,
  // the segment is reversed
  if (left >= right) {
    return;
  }
  // Swap char at left and right pointers
  std::swap(s[left], s[right]);

  // recursive step: move pointers iward
  reverseStringInPlaceRecursive(s, left + 1, right - 1);
}

int main() {
  std::string test1 = "hello";
  std::string test2 = "world";
  std::string test3 = "a";
  std::string test4 = "";
  std::string test5 = "racecar";

  std::cout << "Before: " << test1;
  reverseStringInPlaceRecursive(test1, 0, test1.length() - 1);
  std::cout << ", After: " << test1 << std::endl; // Expected: olleh

  std::cout << "Before: " << test2;
  reverseStringInPlaceRecursive(test2, 0, test2.length() - 1);
  std::cout << ", After: " << test2 << std::endl; // Expected: dlrow

  std::cout << "Before: " << test3;
  reverseStringInPlaceRecursive(test3, 0, test3.length() - 1);
  std::cout << ", After: " << test3 << std::endl; // Expected: a

  std::cout << "Before: " << test4;
  reverseStringInPlaceRecursive(test4, 0, test4.length() - 1);
  std::cout << ", After: " << test4 << std::endl; // Expected:

  std::cout << "Before: " << test5;
  reverseStringInPlaceRecursive(test5, 0, test5.length() - 1);
  std::cout << ", After: " << test5 << std::endl; // Expected: racecar

  return 0;
}