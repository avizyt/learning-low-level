
#include <algorithm>
#include <iostream>
#include <string>

std::string reverseStringRecursive(std::string s) {

  // Base Case: if string is empty or has one char.
  if (s.length() <= 1) {
    return s;
  }

  // Recursive Step:
  // Take the last char, and concatenate it with the reversed version of the
  // rest of the string
  char lastChar = s[s.length() - 1];
  std::string remainingString = s.substr(
      0,
      s.length() - 1); // Substring from index 0 to the last cha (not including)

  return lastChar + reverseStringRecursive(remainingString);
}

int main() {
  std::string test1 = "hello";
  std::string test2 = "world";
  std::string test3 = "a";
  std::string test4 = "";
  std::string test5 = "racecar"; // Palindrome test

  std::cout << "Original: " << test1
            << ", Reversed: " << reverseStringRecursive(test1)
            << std::endl; // Expected: olleh
  std::cout << "Original: " << test2
            << ", Reversed: " << reverseStringRecursive(test2)
            << std::endl; // Expected: dlrow
  std::cout << "Original: " << test3
            << ", Reversed: " << reverseStringRecursive(test3)
            << std::endl; // Expected: a
  std::cout << "Original: " << test4
            << ", Reversed: " << reverseStringRecursive(test4)
            << std::endl; // Expected:
  std::cout << "Original: " << test5
            << ", Reversed: " << reverseStringRecursive(test5)
            << std::endl; // Expected: racecar

  // Compare with std::reverse (iterative)
  std::string s_orig = "example";
  std::string s_rev = s_orig;
  std::reverse(s_rev.begin(), s_rev.end());
  std::cout << "Std reverse for 'example': " << s_rev << std::endl;

  return 0;
}