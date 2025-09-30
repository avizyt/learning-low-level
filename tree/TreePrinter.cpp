#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreePrinter {
public:
  // Method 1: Horizontal tree (rotated)
  static void printHorizontal(TreeNode *root, int space = 0,
                              int levelSpacing = 5) {
    if (root == nullptr)
      return;

    space += levelSpacing;

    // Right child first
    printHorizontal(root->right, space, levelSpacing);

    // Print current node
    cout << string(space, ' ') << root->val << endl;

    // Left child
    printHorizontal(root->left, space, levelSpacing);
  }

  // Method 2: Detailed tree with connectors
  static void printDetailed(TreeNode *root, const string &prefix = "",
                            bool isLeft = true) {
    if (root == nullptr)
      return;

    cout << prefix;
    cout << (isLeft ? "├── " : "└── ");
    cout << root->val << endl;

    string newPrefix = prefix + (isLeft ? "│   " : "    ");

    if (root->left || root->right) {
      if (root->left) {
        printDetailed(root->left, newPrefix, true);
      }
      if (root->right) {
        printDetailed(root->right, newPrefix, false);
      }
    }
  }

  // Method 3: Level order printing
  static void printLevelOrder(TreeNode *root) {
    if (root == nullptr) {
      cout << "Empty tree" << endl;
      return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int levelSize = q.size();
      vector<string> currentLevel;
      bool hasNextLevel = false;

      for (int i = 0; i < levelSize; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node) {
          currentLevel.push_back(to_string(node->val));
          q.push(node->left ? node->left : nullptr);
          q.push(node->right ? node->right : nullptr);
          if (node->left || node->right) {
            hasNextLevel = true;
          }
        } else {
          currentLevel.push_back("null");
          q.push(nullptr);
          q.push(nullptr);
        }
      }

      // Print current level
      for (const string &val : currentLevel) {
        cout << val << " ";
      }
      cout << endl;

      if (!hasNextLevel)
        break;
    }
  }

  // Method 4: Pretty print with proper spacing
  static void printPretty(TreeNode *root) {
    int height = getHeight(root);
    int maxWidth = pow(2, height) - 1;

    vector<vector<string>> levels(height, vector<string>(maxWidth, " "));
    fillLevels(root, levels, 0, 0, maxWidth - 1);

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < maxWidth; j++) {
        cout << levels[i][j];
      }
      cout << endl;
    }
  }

private:
  static int getHeight(TreeNode *node) {
    if (node == nullptr)
      return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
  }

  static void fillLevels(TreeNode *node, vector<vector<string>> &levels,
                         int level, int left, int right) {
    if (node == nullptr)
      return;

    int mid = (left + right) / 2;
    levels[level][mid] = to_string(node->val);

    fillLevels(node->left, levels, level + 1, left, mid - 1);
    fillLevels(node->right, levels, level + 1, mid + 1, right);
  }
};

// Helper function to create example tree
TreeNode *createExampleTree() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  return root;
}

int main() {
  TreeNode *tree = createExampleTree();

  cout << "==================================================" << endl;
  cout << "HORIZONTAL VIEW (Rotated 90° CCW)" << endl;
  cout << "==================================================" << endl;
  TreePrinter::printHorizontal(tree);

  cout << "\n==================================================" << endl;
  cout << "DETAILED VIEW WITH CONNECTORS" << endl;
  cout << "==================================================" << endl;
  TreePrinter::printDetailed(tree);

  cout << "\n==================================================" << endl;
  cout << "LEVEL ORDER VIEW" << endl;
  cout << "==================================================" << endl;
  TreePrinter::printLevelOrder(tree);

  cout << "\n==================================================" << endl;
  cout << "TEST WITH SINGLE NODE" << endl;
  cout << "==================================================" << endl;
  TreeNode *single = new TreeNode(42);
  TreePrinter::printDetailed(single);
  delete single;

  cout << "\n==================================================" << endl;
  cout << "TEST WITH EMPTY TREE" << endl;
  cout << "==================================================" << endl;
  TreePrinter::printDetailed(nullptr);

  // Cleanup
  delete tree->left->left;
  delete tree->left->right;
  delete tree->right->left;
  delete tree->right->right;
  delete tree->left;
  delete tree->right;
  delete tree;

  return 0;
}