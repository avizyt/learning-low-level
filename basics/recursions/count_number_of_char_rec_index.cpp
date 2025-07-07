
#include <iostream>
#include <string>

int countCharRecursiveIndex(const std::string &s, char c, int index) {
  if (index >= s.length()) {
    return 0;
  }

  int count = 0;
  if (s[index] == c) {
    count = 1;
  }

  return count + countCharRecursiveIndex(s, c, index + 1);
}

int main() {
  std::string test1 = "banana";
  char char1 = 'a';
  char char2 = 'n';
  char char3 = 'z';
  std::string test2 = "programming";
  char char4 = 'g';
  std::string test3 = "";
  char char5 = 'x';

  // Initial call will start from index 0
  std::cout << "'" << test1 << "', '" << char1
            << "': " << countCharRecursiveIndex(test1, char1, 0)
            << std::endl; // Expected: 3
  std::cout << "'" << test1 << "', '" << char2
            << "': " << countCharRecursiveIndex(test1, char2, 0)
            << std::endl; // Expected: 2
  std::cout << "'" << test1 << "', '" << char3
            << "': " << countCharRecursiveIndex(test1, char3, 0)
            << std::endl; // Expected: 0
  std::cout << "'" << test2 << "', '" << char4
            << "': " << countCharRecursiveIndex(test2, char4, 0)
            << std::endl; // Expected: 2
  std::cout << "'" << test3 << "', '" << char5
            << "': " << countCharRecursiveIndex(test3, char5, 0)
            << std::endl; // Expected: 0

  return 0;
}