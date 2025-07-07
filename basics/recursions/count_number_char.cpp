#include <iostream>
#include <string>

// recursive function to count character occurrences using substr
int countCharRecursiveSubstr(const std::string &s, char c) {
  if (s.empty()) {
    return 0;
  }

  // check the first character
  int count = 0;
  if (s[0] == c) {
    count = 1;
  }

  // Recursive Step: Add count of first char to count in the rest of the string
  return count + countCharRecursiveSubstr(s.substr(1), c);
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

  std::cout << "'" << test1 << "', '" << char1
            << "': " << countCharRecursiveSubstr(test1, char1)
            << std::endl; // Expected: 3
  std::cout << "'" << test1 << "', '" << char2
            << "': " << countCharRecursiveSubstr(test1, char2)
            << std::endl; // Expected: 2
  std::cout << "'" << test1 << "', '" << char3
            << "': " << countCharRecursiveSubstr(test1, char3)
            << std::endl; // Expected: 0
  std::cout << "'" << test2 << "', '" << char4
            << "': " << countCharRecursiveSubstr(test2, char4)
            << std::endl; // Expected: 2
  std::cout << "'" << test3 << "', '" << char5
            << "': " << countCharRecursiveSubstr(test3, char5)
            << std::endl; // Expected: 0

  return 0;
}