#include <cstddef>

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};
Node *search_list(Node *l, int x) {
  if (l == NULL) {
    return (NULL);
  }
  if (l->data == x) {
    return l;
  } else {
    return search_list(l->next, x);
  }
}

void insert_list(Node **l, int x) {
  Node *p = new Node();
  p->data = x;
  p->next = *l;
  *l = p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Node *n1;
  Node *n2;
  Node *n3;

  n1 = new Node{1};
  n2 = new Node{2};
  n3 = new Node{3};

  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  cout << n1->data << "\n";
  cout << n1->next->data << "\n";
  cout << n1->next->next->data << "\n";

  cout << search_list(n1, 2)->data << "\n";
  insert_list(*n1, 5);

  return 0;
}