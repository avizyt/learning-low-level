

class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {};
};

TreeNode *invertTree(TreeNode *root) {
  if (root == nullptr)
    return nullptr;

  // swap children
  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;

  // recursive invert subtree
  invertTree(root->left);
  invertTree(root->right);

  return root;
}

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);

  p->left->left = new TreeNode(4);
  p->left->right = new TreeNode(5);

  invertTree(p);

  cout << p->data << " " << p->left->data << " " << p->right->data;

  return 0;
}