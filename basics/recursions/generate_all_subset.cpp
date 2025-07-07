/*
Problem: Generate All Subsets of a Set/Vector
Problem Statement: Given a collection of distinct integers, return all possible
subsets (the power set).

Example:
Input: nums = [1, 2, 3]
Output:
[
  [],
  [1],
  [2],
  [3],
  [1, 2],
  [1, 3],
  [2, 3],
  [1, 2, 3]
]
*/

#include <vector>
void generateSubsets(const std::vector<int> &nums, int index,
                     std::vector<int> &currentSubset,
                     std::vector<std::vector<int>> &result) {
  if (index == nums.size()) {
    result.push_back(currentSubset);
    return;
  }

  // 1. Exclude the current element (nums[index])
  generateSubsets(nums, index + 1, currentSubset, result);

  // 2. Include the current element(nums[index])
  currentSubset.push_back(nums[index]);
  generateSubsets(nums, index + 1, currentSubset, result);

  // Backtrack: Remove the current element for the next path/caller
  currentSubset.pop_back();
}