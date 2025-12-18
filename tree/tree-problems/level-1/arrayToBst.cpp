#include <vector>
class TreeNode {

public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode *buildBST(std::vector<int> &arr, int left, int right) {
  if (left > right)
    return nullptr;

  int mid = left + (right - left) / 2;
  TreeNode *root = new TreeNode(arr[mid]);

  root->left = buildBST(arr, left, mid - 1);
  root->right = buildBST(arr, mid + 1, right);

  return root;
}

TreeNode *sortedArrayToBst(std::vector<int> &arr) {
  return buildBST(arr, 0, arr.size() - 1);
}

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> arr = {10, 12, 14, 16, 18, 20, 22};

  TreeNode *root = sortedArrayToBst(arr);

  cout << root->data << " " << root->left->data << " " << root->right->data;

  return 0;
}