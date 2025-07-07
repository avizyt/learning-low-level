
#include <iostream>
#include <string>
bool isPalindromeRecursive(const std::string &s, int left, int right) {
  if (left >= right) {
    return true;
  }

  // Check if outer char match
  if (s[left] != s[right]) {
    return false;
  }
  return isPalindromeRecursive(s, left + 1, right - 1);
}

int main() {
  std::string test1 = "madam";
  std::string test2 = "racecar";
  std::string test3 = "hello";
  std::string test4 = "a";
  std::string test5 = "";
  std::string test6 = "ab";

  std::cout << "'" << test1 << "' is a palindrome: "
            << (isPalindromeRecursive(test1, 0, test1.length() - 1) ? "Yes"
                                                                    : "No")
            << std::endl; // Expected: Yes
  std::cout << "'" << test2 << "' is a palindrome: "
            << (isPalindromeRecursive(test2, 0, test2.length() - 1) ? "Yes"
                                                                    : "No")
            << std::endl; // Expected: Yes
  std::cout << "'" << test3 << "' is a palindrome: "
            << (isPalindromeRecursive(test3, 0, test3.length() - 1) ? "Yes"
                                                                    : "No")
            << std::endl; // Expected: No
  std::cout << "'" << test4 << "' is a palindrome: "
            << (isPalindromeRecursive(test4, 0, test4.length() - 1) ? "Yes"
                                                                    : "No")
            << std::endl; // Expected: Yes
  std::cout << "'" << test5 << "' is a palindrome: "
            << (isPalindromeRecursive(test5, 0, test5.length() - 1) ? "Yes"
                                                                    : "No")
            << std::endl; // Expected: Yes
  std::cout << "'" << test6 << "' is a palindrome: "
            << (isPalindromeRecursive(test6, 0, test6.length() - 1) ? "Yes"
                                                                    : "No")
            << std::endl; // Expected: No

  // A simpler wrapper function for convenience:
  auto checkPalindrome = [](const std::string &s) {
    return isPalindromeRecursive(s, 0, s.length() - 1);
  };
  std::cout << "'level' is a palindrome: "
            << (checkPalindrome("level") ? "Yes" : "No") << std::endl;

  return 0;
}
