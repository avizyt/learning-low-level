#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Vector Operation: \n";
  std::vector<char> greet;
  std::string hello = "Hello, Distopia!";
  for (char item : hello) {
    greet.push_back(item);
  }
  std::cout << " Greeting From Vector: \n";
  for (char item : greet) {
    std::cout << item << " ";
  }
}