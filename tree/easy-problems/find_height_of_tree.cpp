/*
Problem 1: Find the Height/Maximum Depth of a Binary Tree
Description:
Given the root of a binary tree, return its maximum depth.
The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Example:
Input:
     3
    / \
   9  20
     /  \
    15   7
Output: 3 (Path: 3 -> 20 -> 7, or 3 -> 20 -> 15)
*/
#include <algorithm>
#include <iostream>
#include <vector>

// Definition for a binary tree node using raw pointers.
template <typename T> struct TreeNode {
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  // Constructor
  TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}

  // Destructor: IMPORTANT for manual memory management
  ~TreeNode() {
    // Recursively delete children
    delete left;
    delete right;
    // std::cout << "Deleting node: " << val << std::endl; // For debugging
    // deletions
  }
};

class Solution {
public:
  template <typename T> int maxDepth(TreeNode<T> *root) {
    if (root == nullptr) {
      return 0;
    }

    int left_depth = maxDepth(root->left);

    int right_depth = maxDepth(root->right);

    return 1 + std::max(left_depth, right_depth);
  }
};

// Helper function to build a tree for testing using raw pointers.
// IMPORTANT: This function allocates memory using 'new'.
// The caller is responsible for deleting the returned root node,
// which will then recursively delete the entire tree via the TreeNode
// destructor.
TreeNode<int> *buildTreeRaw(const std::vector<int *> &nodes, int index) {
  if (index >= nodes.size() || nodes[index] == nullptr) {
    return nullptr;
  }
  TreeNode<int> *root = new TreeNode<int>(*nodes[index]);
  root->left = buildTreeRaw(nodes, 2 * index + 1);
  root->right = buildTreeRaw(nodes, 2 * index + 2);
  return root;
}

int main() {
  Solution sol;

  // Test Case 1
  std::vector<int> vals1 = {3, 9, 20, 15, 7};
  std::vector<int *> nodes1_ptr = {&vals1[0], &vals1[1], &vals1[2], nullptr,
                                   nullptr,   &vals1[3], &vals1[4]};
  TreeNode<int> *root1 = buildTreeRaw(nodes1_ptr, 0); // Allocate tree
  std::cout << "Test Case 1 (Depth 3): " << sol.maxDepth(root1) << std::endl;
  delete root1; // Release memory

  // Test Case 2
  std::vector<int> vals2 = {1, 2};
  std::vector<int *> nodes2_ptr = {&vals2[0], nullptr, &vals2[1]};
  TreeNode<int> *root2 = buildTreeRaw(nodes2_ptr, 0);
  std::cout << "Test Case 2 (Depth 2): " << sol.maxDepth(root2) << std::endl;
  delete root2;

  // Test Case 3: Empty tree (no allocation needed for nullptr)
  TreeNode<int> *root3 = nullptr;
  std::cout << "Test Case 3 (Depth 0 - Empty): " << sol.maxDepth(root3)
            << std::endl;
  // No delete needed for nullptr

  // Test Case 4: Single node tree
  TreeNode<int> *root4 = new TreeNode<int>(7); // Allocate single node
  std::cout << "Test Case 4 (Depth 1 - Single Node): " << sol.maxDepth(root4)
            << std::endl;
  delete root4; // Release memory

  // Test Case 5: Skewed tree
  std::vector<int> vals5 = {1, 2, 3};
  std::vector<int *> nodes5_ptr = {&vals5[0], &vals5[1], nullptr, &vals5[2]};
  TreeNode<int> *root5 = buildTreeRaw(nodes5_ptr, 0);
  std::cout << "Test Case 5 (Depth 3 - Skewed Left): " << sol.maxDepth(root5)
            << std::endl;
  delete root5;

  return 0;
}