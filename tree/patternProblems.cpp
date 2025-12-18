#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
  int value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  BinaryTreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int maxDepth(BinaryTreeNode *root) {
  if (root == nullptr)
    return 0;

  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int depth(BinaryTreeNode *root, BinaryTreeNode *target, int currDepth = 0) {
  if (root == nullptr)
    return -1;
  if (root == target)
    return currDepth;

  int leftDepth = depth(root->left, target, currDepth + 1);
  if (leftDepth != -1)
    return leftDepth;

  return depth(root->right, target, currDepth + 1);
}

bool isValid(BinaryTreeNode *root, long min_val = LONG_MIN,
             long max_val = LONG_MAX) {
  if (root == nullptr)
    return true;

  if (root->value <= min_val || root->value >= max_val) {
    return false;
  }

  return isValid(root->left, min_val, root->value) &&
         isValid(root->right, root->value, max_val);
}

int heightOfTree(BinaryTreeNode *root) {
  if (root == nullptr)
    return 0;

  int leftHeight = heightOfTree(root->left);
  int rightHeight = heightOfTree(root->right);

  return 1 + max(leftHeight, rightHeight);
}

int main() {
  BinaryTreeNode *root = new BinaryTreeNode(1);
  root->left = new BinaryTreeNode(2);
  root->right = new BinaryTreeNode(3);
  root->left->left = new BinaryTreeNode(4);
  root->left->right = new BinaryTreeNode(5);
  root->right->left = new BinaryTreeNode(6);
  root->right->right = new BinaryTreeNode(7);

  int max_depth = maxDepth(root);
  cout << "Max Depth: " << max_depth;

  cout << "\n"
       << "Is BST: " << isValid(root);

  cout << "\n" << "Height of The Tree: " << heightOfTree(root);

  cout << "\n" << "Depth from 1 to 5: " << depth(root, root->left->right);

  return 0;
}