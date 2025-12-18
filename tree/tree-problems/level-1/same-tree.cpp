

#include <string>
class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {};
};

bool checkVal(TreeNode *node1, TreeNode *node2) {
  if (node1->data == node2->data) {
    return true;
  } else {
    return false;
  }
}
bool checkIdentical(TreeNode *root1, TreeNode *root2) {
  if (root1 == nullptr && root2 == nullptr) {

    return true;
  } else if (root1 == nullptr && root2 != nullptr) {
    return false;
  } else if (root1 != nullptr && root2 == nullptr) {
    return false;
  } else if (root1->data != root2->data) {
    return false;
  } else {
    return checkIdentical(root1->left, root2->left) &&
           checkIdentical(root1->right, root2->right);
  }
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

  TreeNode *q = new TreeNode(1);
  q->left = new TreeNode(2);
  q->right = new TreeNode(6);

  q->left->left = new TreeNode(4);
  q->left->right = new TreeNode(5);

  string val = checkIdentical(p, q) ? "TRUE" : "FALSE";

  std::cout << "Is Same: " << val << std::endl;
  return 0;
}