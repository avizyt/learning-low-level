

#include <algorithm>
#include <iostream>
#include <queue>
class TreeNode {

public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// recursive DFS
int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

// BFS

int maxDepthBFS(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  std::queue<TreeNode *> q;
  q.push(root);
  int depth = 0;

  while (!q.empty()) {
    int levelSize = q.size();
    for (int i = 0; i < levelSize; ++i) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    depth++;
  }
  return depth;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  std::cout << maxDepth(root) << "\n";
}