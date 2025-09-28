#include <cstddef>
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *link;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Node *A = new Node;

  A->data = 2;

  A->link = NULL;

  cout << A->data << "\n";

  return 0;
}