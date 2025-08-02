#include <iostream>
#include <vector>

void printSubsets(const std::vector<std::vector<int>> &subsets) {
  std::cout << " [\n";
  for (const auto &subset : subsets) {
    std::cout << " [";
    for (size_t i = 0; i < subset.size(); ++i) {
      std::cout << subset[i];
      if (i < subset.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "],\n";
  }
  std::cout << "]\n";
}

void generateSubsets(const std::vector<int> &nums, int index,
                     std::vector<int> &currentSubset,
                     std::vector<std::vector<int>> &result) {
  if (index == nums.size()) {
    result.push_back(currentSubset);
    return;
  }

  // recursive step

  // 1.exclude the current element (nums[index])
  // don't add nums[index] to currentSubset. Just move to the next element
  generateSubsets(nums, index + 1, currentSubset, result);

  // 2. include the current element (nums[index])
  currentSubset.push_back(nums[index]);
  generateSubsets(nums, index + 1, currentSubset, result);

  currentSubset.pop_back();
}

int main() {
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<std::vector<int>> allSubsets1;
  std::vector<int> currentSubset1;

  std::cout << "Subsets for [1, 2, 3]:\n";
  generateSubsets(nums1, 0, currentSubset1, allSubsets1);
  printSubsets(allSubsets1);

  std::vector<int> nums2 = {4, 5};
  std::vector<std::vector<int>> allSubsets2;
  std::vector<int> currentSubset2;

  std::cout << "\nSubsets for [4, 5]:\n";
  generateSubsets(nums2, 0, currentSubset2, allSubsets2);
  printSubsets(allSubsets2);

  std::vector<int> nums3 = {}; // Empty set
  std::vector<std::vector<int>> allSubsets3;
  std::vector<int> currentSubset3;

  std::cout << "\nSubsets for []:\n";
  generateSubsets(nums3, 0, currentSubset3, allSubsets3);
  printSubsets(allSubsets3); // Expected: [ [] ]

  return 0;
}