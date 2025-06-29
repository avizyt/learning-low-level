#include <iostream>
void func(int arr[], int length) {
  // return pointer size, not useful here.
  //   size_t test = sizeof(arr);

  for (int i = 0; i < length; ++i) {
    std::cout << arr[i] << " ";
  }
}
int main() {
  int i[5]{1, 2, 3, 4, 5};

  // sizeof(i) = total bytes
  int j = sizeof(i) / sizeof(i[0]);
  std::cout << "Array size: " << sizeof(i) << "\n";
  std::cout << "simple element size of the array: " << j << std::endl;

  func(i, j);
}