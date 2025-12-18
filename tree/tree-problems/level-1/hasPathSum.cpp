/**
Given root and targetSum, return true if tree has root-to-leaf path where sum of
values equals targetSum.
*/

#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {};
};

bool hasPathSum(TreeNode *root, int targetSum) {
  if (root == nullptr)
    return false;

  if (root->left == nullptr && root->right == nullptr) {
    return root->data == targetSum;
  }

  int remain = targetSum - root->data;
  return (hasPathSum(root->left, remain) || hasPathSum(root->right, remain));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);

  p->left->left = new TreeNode(4);
  p->left->right = new TreeNode(6);

  int targetsum1 = 9;
  int targetsum2 = 7;

  cout << (string)(hasPathSum(p, targetsum1) ? "True" : "False") << "\n";
  cout << (string)(hasPathSum(p, targetsum2) ? "True" : "False") << "\n";

  return 0;
}