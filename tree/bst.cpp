

#include <iostream>
#include <memory>
#include <queue>
template <typename T> struct BinaryTreeNode {
  T data;
  std::shared_ptr<BinaryTreeNode<T>> left;
  std::shared_ptr<BinaryTreeNode<T>> right;

  BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// 2. Helper function to build a simple Binary Tree
std::shared_ptr<BinaryTreeNode<int>> buildExampleBinaryTree() {
  //       1
  //      / \
  //     2   3
  //    / \
  //   4   5

  auto root = std::make_shared<BinaryTreeNode<int>>(1);
  root->left = std::make_shared<BinaryTreeNode<int>>(2);
  root->right = std::make_shared<BinaryTreeNode<int>>(3);
  root->left->left = std::make_shared<BinaryTreeNode<int>>(4);
  root->left->right = std::make_shared<BinaryTreeNode<int>>(5);
  //   root->right->right = std::make_shared<BinaryTreeNode<int>>(7);
  return root;
}

// In-order DFS (recursive)
// left -> root -> right
template <typename T>
void inOrderTraversal(std::shared_ptr<BinaryTreeNode<T>> node) {
  if (!node) {
    return;
  }
  inOrderTraversal(node->left);
  std::cout << node->data << " ";
  inOrderTraversal(node->right);
}

// post order
// left -> right -> root
template <typename T>
void postOrderTraversal(std::shared_ptr<BinaryTreeNode<T>> node) {
  if (!node) {
    return;
  }
  inOrderTraversal(node->left);
  inOrderTraversal(node->right);
  std::cout << node->data << " ";
}

// pre order
// root -> left -> right
template <typename T>
void preOrderTraversal(std::shared_ptr<BinaryTreeNode<T>> node) {
  if (!node) {
    return;
  }
  std::cout << node->data << " ";
  inOrderTraversal(node->left);
  inOrderTraversal(node->right);
}

// Level order traversal (BFS)
template <typename T>
void levelOrderTraversal(std::shared_ptr<BinaryTreeNode<T>> root) {
  if (!root) {
    return;
  }
  std::queue<std::shared_ptr<BinaryTreeNode<T>>> q;
  q.push(root);

  std::cout << "Level-order Traversal: ";
  while (!q.empty()) {
    std::shared_ptr<BinaryTreeNode<T>> current = q.front();
    q.pop();
    std::cout << current->data << " ";

    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }
  std::cout << "\n";
}

int main_binary_tree() {
  std::cout << "--- Binary Tree Example ---\n";
  auto binaryRoot = buildExampleBinaryTree();

  std::cout << "In-order Traversal (LNR): ";
  inOrderTraversal(binaryRoot); // Expected: 4 2 5 1 3
  std::cout << std::endl;

  std::cout << "Pre-order Traversal (NLR): ";
  preOrderTraversal(binaryRoot); // Expected: 1 2 4 5 3
  std::cout << std::endl;

  std::cout << "Post-order Traversal (LRN): ";
  postOrderTraversal(binaryRoot); // Expected: 4 5 2 3 1
  std::cout << std::endl;

  levelOrderTraversal(binaryRoot); // Expected: 1 2 3 4 5

  return 0;
}

int main() {
  main_binary_tree();
  return 0;
}