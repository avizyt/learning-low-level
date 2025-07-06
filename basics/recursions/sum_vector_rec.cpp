
#include <iostream>
#include <numeric>
#include <vector>
typedef long long ll;

ll sumVectorRecursive(const std::vector<int> &arr, int index) {
  // Base Case: If the index is negative, it means we've processed all elements
  // or are given an empty range to sum.
  if (index < 0) {
    return 0;
  }

  // Recursive Step: Sum of elements up to 'index' is arr[index] + sum of
  // elements up to 'index-1'
  return arr[index] + sumVectorRecursive(arr, index - 1);
}

int main() {
  std::vector<int> myVector = {1, 2, 3, 4, 5};
  std::vector<int> emptyVector = {};
  std::vector<int> singleElementVector = {100};

  // Call with last valid index (size -1)
  std::cout << "Sum of myVector: "
            << sumVectorRecursive(myVector, myVector.size() - 1) << "\n";
  std::cout << "Sum of emptyVector: "
            << sumVectorRecursive(emptyVector, emptyVector.size() - 1) << "\n";
  std::cout << "Sum of singleElementVector: "
            << sumVectorRecursive(singleElementVector,
                                  singleElementVector.size() - 1)
            << "\n";

  // compare with iterative/standard library sum
  ll iterativeSum = 0;
  for (int x : myVector) {
    iterativeSum += x;
  }
  std::cout << "Iterative sum of myVector: " << iterativeSum << std::endl;

  std::cout << "Std accumulate sum of myVector: "
            << std::accumulate(myVector.begin(), myVector.end(), 0LL)
            << std::endl;

  return 0;
}