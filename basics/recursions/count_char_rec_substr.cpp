#include <iostream>
#include <string>

int countCharRecursiveSubstr(const std::string &s, char targetChar) {
  // if string is empty, count is 0
  if (s.empty()) {
    return 0;
  }

  // check the first char
  int count = 0;
  if (s[0] == targetChar) {
    count = 1;
  }

  return count + countCharRecursiveSubstr(s.substr(1), targetChar);
}

int main() {
  std::string test1 = "banana";
  char char1 = 'a';
  //   char char2 = 'n';
  //   char char3 = 'z';

  std::string test2 = "programming";
  char char4 = 'g';

  std::cout << " " << test1 << "', '" << char1
            << "': " << countCharRecursiveSubstr(test1, char1) << std::endl;
  std::cout << " " << test2 << "', '" << char4
            << "': " << countCharRecursiveSubstr(test2, char4) << std::endl;
}