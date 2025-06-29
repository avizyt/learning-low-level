
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  int val;

  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }

    // Recursive invert the left and right subtree
    // Store the results in temporary variables first
    TreeNode *inverted_left_subtree = invertTree(root->left);
    TreeNode *inverted_right_subtree = invertTree(root->right);

    // Now, swap the children of the current node
    root->left = inverted_left_subtree;
    root->right = inverted_right_subtree;

    // return the current (inverted) root
    return root;
  }
};

TreeNode *buildTreeRaw(const std::vector<int *> &nodes_data, int index) {
  if (index >= nodes_data.size() || nodes_data[index] == nullptr) {
    return nullptr;
  }

  TreeNode *root = new TreeNode(*nodes_data[index]);
  root->left = buildTreeRaw(nodes_data, 2 * index + 1);
  root->right = buildTreeRaw(nodes_data, 2 * index + 2);

  return root;
}

void printTreeLevelOrder(TreeNode *root) {
  if (root == nullptr) {
    std::cout << "Tree is empty.\n";
    return;
  }
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();

    if (current) {
      std::cout << current->val << " ";
      q.push(current->left);
      q.push(current->right);
    } else {
      std::cout << "null ";
    }
  }
  std::cout << "\n";
}

int main() {
  Solution sol;

  // Test Case 1: Example from problem description
  // Original:
  //      4
  //     / \
    //    2   7
  //   / \ / \
    //  1  3 6  9
  std::vector<int> vals1 = {4, 2, 7, 1, 3, 6, 9};
  std::vector<int *> nodes1_data = {&vals1[0], &vals1[1], &vals1[2], &vals1[3],
                                    &vals1[4], &vals1[5], &vals1[6]};
  TreeNode *root1 = buildTreeRaw(nodes1_data, 0);
  std::cout << "Test Case 1 - Original Tree (Level Order): ";
  printTreeLevelOrder(root1);
  root1 = sol.invertTree(root1); // Invert
  std::cout << "Test Case 1 - Inverted Tree (Level Order): ";
  printTreeLevelOrder(root1); // Expected: 4 7 2 9 6 3 1
  delete root1;               // Cleanup

  // Test Case 2: Simple tree
  // Original:
  //      1
  //       \
    //        2
  std::vector<int> vals2 = {1, 2};
  std::vector<int *> nodes2_data = {&vals2[0], nullptr, &vals2[1]};
  TreeNode *root2 = buildTreeRaw(nodes2_data, 0);
  std::cout << "\nTest Case 2 - Original Tree (Level Order): ";
  printTreeLevelOrder(root2);
  root2 = sol.invertTree(root2); // Invert
  std::cout << "Test Case 2 - Inverted Tree (Level Order): ";
  printTreeLevelOrder(root2); // Expected: 1 2 null null null
  delete root2;

  // Test Case 3: Empty tree
  TreeNode *root3 = nullptr;
  std::cout << "\nTest Case 3 - Original Tree (Level Order): ";
  printTreeLevelOrder(root3);
  root3 = sol.invertTree(root3); // Invert
  std::cout << "Test Case 3 - Inverted Tree (Level Order): ";
  printTreeLevelOrder(root3); // Expected: Tree is empty.
  // No delete needed for nullptr

  // Test Case 4: Single node tree
  TreeNode *root4 = new TreeNode(5);
  std::cout << "\nTest Case 4 - Original Tree (Level Order): ";
  printTreeLevelOrder(root4);
  root4 = sol.invertTree(root4); // Invert
  std::cout << "Test Case 4 - Inverted Tree (Level Order): ";
  printTreeLevelOrder(root4); // Expected: 5 null null
  delete root4;

  // Test Case 5: Skewed tree (left)
  // Original:
  //      1
  //     /
  //    2
  //   /
  //  3
  std::vector<int> vals5 = {1, 2, 3};
  std::vector<int *> nodes5_data = {&vals5[0], &vals5[1], nullptr, &vals5[2],
                                    nullptr,   nullptr,   nullptr};
  TreeNode *root5 = buildTreeRaw(nodes5_data, 0);
  std::cout << "\nTest Case 5 - Original Tree (Level Order): ";
  printTreeLevelOrder(root5);
  root5 = sol.invertTree(root5); // Invert
  std::cout << "Test Case 5 - Inverted Tree (Level Order): ";
  printTreeLevelOrder(root5); // Expected: 1 null 2 null 3 null null null null
  delete root5;

  return 0;
}