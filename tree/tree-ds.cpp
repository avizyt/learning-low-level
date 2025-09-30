#include <iostream>
#include <vector>

using namespace std;

template <typename T> class TreeNode {
public:
  T value;
  vector<TreeNode *> children;

  TreeNode(T val) : value(val) {}

  void addChild(TreeNode *child) { children.push_back(child); }
};

int main() {
  TreeNode<string> *root = new TreeNode<string>("A");
  TreeNode<string> *child1 = new TreeNode<string>("B");
  TreeNode<string> *child2 = new TreeNode<string>("c");

  cout << "Root: " << root->value << "\n";
  cout << "C1: " << child1->value << "\n";
  cout << "C2: " << child2->value << "\n";
}