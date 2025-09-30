#include <iostream>
#include <string>

class BSTNode {
public:
  int value;
  BSTNode *left;
  BSTNode *right;

  BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

BSTNode *bstInsert(BSTNode *root, int val) {
  if (root == nullptr) {
    return new BSTNode(val);
  }

  if (val < root->value) {
    root->left = bstInsert(root->left, val);
  } else {
    root->right = bstInsert(root->right, val);
  }

  return root;
}

void printTree(BSTNode *root, int space = 0, int levelSpacing = 5) {
  if (root == nullptr)
    return;

  space += levelSpacing;

  printTree(root->right, space, levelSpacing);

  std::cout << std::string(space, ' ') << root->value << "\n";

  printTree(root->left, space, levelSpacing);
}

BSTNode *bstSearch(BSTNode *root, int val) {
  if (root == nullptr || root->value == val) {
    return root;
  }
  if (val < root->value) {
    return bstSearch(root->left, val);
  } else {
    return bstSearch(root->right, val);
  }
}
int main() {
  BSTNode *root = new BSTNode(6);
  bstInsert(root, 5);
  bstInsert(root, 3);
  bstInsert(root, 7);
  bstInsert(root, 1);
  bstInsert(root, 4);
  printTree(root);

  std::cout << "Searching Value in Binary Tree" << "\n";
  std::cout << "Value: " << bstInsert(root, 6)->value << std::endl;
}