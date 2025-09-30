#include <iostream>
using namespace std;

template <typename T> class BinaryTreeNode {
public:
  T value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  BinaryTreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  root->left = new BinaryTreeNode<int>(2);
  root->right = new BinaryTreeNode<int>(3);

  root->left->left = new BinaryTreeNode<int>(4);

  cout << "root ->" << root->value << "\n";
  cout << "root.left ->" << root->left->value << "\n";
  cout << "root.right->" << root->right->value << "\n";
  cout << "root.left.left ->" << root->left->left->value << "\n";

  return 0;
}