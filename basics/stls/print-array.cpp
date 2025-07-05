
#include <iostream>
void printArr(int *arr, int n) {
  if (n == 0) {
    return;
  }
  std::cout << arr[n - 1] << " ";
  printArr(arr, n - 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  printArr(arr, 5);
}