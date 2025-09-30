#include <iostream>

#include <queue>
#include <string>
#include <vector>

class BinaryTreeNode {
public:
  int value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  BinaryTreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void preOrder(BinaryTreeNode *node) {
  if (node != nullptr) {
    std::cout << node->value;
    preOrder(node->left);
    preOrder(node->right);
  }
}

void InOrder(BinaryTreeNode *node) {
  if (node != nullptr) {
    InOrder(node->left);
    std::cout << node->value;
    InOrder(node->right);
  }
}

void postOrder(BinaryTreeNode *node) {
  if (node != nullptr) {
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value;
  }
}

void displayTree(BinaryTreeNode *root) {
  if (root != nullptr) {
    displayTree(root->left);
    displayTree(root->right);
    std::cout << root->value;
  }
}

void bfs(BinaryTreeNode *root) {
  if (root == nullptr)
    return;

  std::queue<BinaryTreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    BinaryTreeNode *curr = q.front();
    q.pop();
    std::cout << curr->value << " ";

    if (curr->left != nullptr) {
      q.push(curr->left);
    }
    if (curr->right != nullptr) {
      q.push(curr->right);
    }
  }
}

// level order traversal
std::vector<std::vector<int>> levelOrderTraversal(BinaryTreeNode *root) {
  std::vector<std::vector<int>> result;
  if (root == nullptr)
    return result;

  std::queue<BinaryTreeNode *> q;
  q.push(root);

  while (!q.empty()) {

    int levelSize = q.size();
    std::vector<int> currLevel;

    for (int i = 0; i < levelSize; ++i) {
      BinaryTreeNode *node = q.front();
      q.pop();
      currLevel.push_back(node->value);

      if (node->left != nullptr)
        q.push(node->left);

      if (node->right != nullptr)
        q.push(node->right);
    }
    result.push_back(currLevel);
  }
  return result;
}

// printing the tree
void printTree(BinaryTreeNode *root, int space = 0, int levelSpacing = 5) {
  if (root == nullptr)
    return;

  space += levelSpacing;

  printTree(root->right, space, levelSpacing);

  std::cout << std::string(space, ' ') << root->value << "\n";

  printTree(root->left, space, levelSpacing);
}

int main() {

  BinaryTreeNode *root = new BinaryTreeNode(1);
  root->left = new BinaryTreeNode(2);
  root->right = new BinaryTreeNode(3);
  root->left->left = new BinaryTreeNode(4);
  root->left->right = new BinaryTreeNode(5);
  root->right->left = new BinaryTreeNode(6);
  root->right->right = new BinaryTreeNode(7);

  //   displayTree(root);
  //   printTree(root);
  //   std::cout << "\n" << "PreOrder Traversal: ";
  //   preOrder(root);
  //   std::cout << "\n" << "InOrder Traversal: ";
  //   InOrder(root);
  //   std::cout << "\n" << "PostOrder Traversal: ";
  //   postOrder(root);

  // Breadth First Search
  std::cout << "BFS:" << "\n";
  bfs(root);

  std::cout << "\n" << "Level order Traversal:" << "\n";
  // Level order Traversal
  std::vector<std::vector<int>> levelOrderResult = levelOrderTraversal(root);
  int i = 0;
  for (std::vector<int> item : levelOrderResult) {
    std::cout << "Level " << i << ": ";
    for (int val : item) {
      std::cout << val << " ";
    }
    std::cout << "\n";
    i += 1;
  }
}