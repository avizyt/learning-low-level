
#include <iostream>
#include <memory>
#include <ostream>
#include <queue>
#include <string>
#include <vector>

// Node structure for generic tree
template <typename T> struct TreeNode {
  T data;
  std::vector<std::shared_ptr<TreeNode<T>>> children;

  // constructor
  TreeNode(T val) : data(val) {}
};

// Demo tree
std::shared_ptr<TreeNode<std::string>> buildExampleGenericTree() {
  auto root = std::make_shared<TreeNode<std::string>>("Documents");

  auto personal = std::make_shared<TreeNode<std::string>>("Personal");
  auto work = std::make_shared<TreeNode<std::string>>("work");
  auto photos = std::make_shared<TreeNode<std::string>>("Photos");

  root->children.push_back(personal);
  root->children.push_back(work);
  root->children.push_back(photos);

  // Children of "Personal"
  personal->children.push_back(
      std::make_shared<TreeNode<std::string>>("Resume.pdf"));
  personal->children.push_back(
      std::make_shared<TreeNode<std::string>>("Letter.docx"));

  // Children of "Work"
  auto projects = std::make_shared<TreeNode<std::string>>("Projects");
  work->children.push_back(projects);
  work->children.push_back(std::make_shared<TreeNode<std::string>>("Reports"));

  // Children of "Projects"
  projects->children.push_back(
      std::make_shared<TreeNode<std::string>>("Project A"));
  projects->children.push_back(
      std::make_shared<TreeNode<std::string>>("Project B"));

  // Children of "Photos"
  photos->children.push_back(
      std::make_shared<TreeNode<std::string>>("Vacation_2023"));
  photos->children.push_back(
      std::make_shared<TreeNode<std::string>>("Family_2024"));

  return root;
}

// 3. Tree Traversal: Depth-First Search (DFS) - Pre-order
// Prints the node, then recursively visits its children.
template <typename T>
void printTreeDFS(std::shared_ptr<TreeNode<T>> node, int depth = 0) {
  if (!node) {
    return;
  }
  for (int i = 0; i < depth; ++i) {
    std::cout << " ";
  }
  std::cout << "- " << node->data << "\n";
  for (const auto &child : node->children) {
    printTreeDFS(child, depth + 1);
  }
}

// 4. Tree Traversal: Breadth-First Search (BFS) - Level-order
// Prints nodes level by level.
template <typename T> void printTreeBFS(std::shared_ptr<TreeNode<T>> root) {
  if (!root) {
    return;
  }

  std::queue<std::shared_ptr<TreeNode<T>>> q;
  q.push(root);

  std::cout << "\n--- BFS Traversal ---" << std::endl;
  while (!q.empty()) {
    int level_size = q.size(); // Number of nodes at current level
    for (int i = 0; i < level_size; ++i) {
      std::shared_ptr<TreeNode<T>> current = q.front();
      q.pop();
      std::cout << current->data << " ";

      for (const auto &child : current->children) {
        q.push(child);
      }
    }
    std::cout << std::endl; // Newline after each level
  }
}

int main_generic_tree() {
  std::cout << "--- Generic Tree (File System Example) ---\n";
  auto fileSystemRoot = buildExampleGenericTree();

  std::cout << "\n--- DFS (Pre-order) Traversal ---" << std::endl;
  printTreeDFS(fileSystemRoot);

  printTreeBFS(fileSystemRoot);

  return 0;
}

int main() {
  main_generic_tree();
  return 0;
}