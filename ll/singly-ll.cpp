#include <iostream>

template <typename T> struct Node {
  T data;
  Node<T> *next;

  Node(T val) : data(val), next(nullptr) {}
};

template <typename T> class SinglyLinkedList {
public:
  Node<T> *head;
  SinglyLinkedList() : head(nullptr) {}

  ~SinglyLinkedList() {
    Node<T> *current = head;
    Node<T> *next_node;
    while (current != nullptr) {
      next_node = current->next;
      delete current;
      current = next_node;
    }
    head = nullptr;
  }

  // insert at head
  void insertAtHead(T val) {
    Node<T> *newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
  }

  bool isEmpty() {
    if (head != nullptr) {
      return false;
    }
    return true;
  }

  // insert ar tail
  void insertAtEnd(T val) {
    Node<T> *newNode = new Node<T>(val);
    // check if the list is empty then new node will be the head
    if (head == nullptr) {
      head = newNode;
      return;
    }

    // Traverse to the last node
    Node<T> *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }

    curr->next = newNode;
  }

  // insert after any node's value
  void insertAfterVal(T nodeToFindValue, T val) {
    Node<T> *curr = head;
    // Find the node after which we want to insert
    while (curr != nullptr && curr->data != nodeToFindValue) {
      curr = curr->next;
    }

    // if nodetofindvalue was not found, or if list is empty
    if (curr == nullptr) {
      std::cout << "Node with value " << nodeToFindValue
                << " not found, Cannot insert." << "\n";
      return;
    }

    // now curr node is prevNode
    Node<T> *newNode = new Node<T>(val);
    newNode->next = curr->next;
    curr->next = newNode;
  }
  // insert after a node
  void insertAfterNode(Node<T> *prevNode, T val) {
    Node<T> *curr = head;
    while (curr != nullptr && curr != prevNode) {
      curr = curr->next;
    }

    if (curr == nullptr) {
      std::cout << "Node " << prevNode->data << " not found.";
      return;
    }

    Node<T> *newNode = new Node<T>(val);
    newNode->next = curr->next;
    curr->next = newNode;
  }

  // deletion of a node
  void deletionFromHead() {
    if (isEmpty()) {
      std::cout << " List is emmpty.Cannot delete from head." << "\n";
      return;
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
  }

  void deleteionFromEnd() {
    if (head == nullptr) {
      std::cout << " List is empty.Cannot delete from End." << "\n";
      return;
    }
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    while (curr != nullptr) {
      prev = curr;
      curr = curr->next;
    }

    prev->next = nullptr;
    delete curr;
  }

  // delete node
  void deleteNode(T valToDelete) {
    if (head == nullptr) {
      std::cout << "List is empty. Cannot delete " << valToDelete << "."
                << std::endl;
      return;
    }

    // if the head node contains the value
    if (head->data == valToDelete) {
      deletionFromHead();
      return;
    }
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    // traverse to find the node and its prev node
    while (curr != nullptr && curr->data != valToDelete) {
      prev = curr;
      curr = curr->next;
    }

    // If current is nullptr, val was not found
    if (curr == nullptr) {
      std::cout << "Node with value " << valToDelete << " not found."
                << std::endl;
      return;
    }

    // value found: 'curr' points to the node to delete
    prev->next = curr->next;
    delete curr;
  }

  bool find(T valToFind) const {
    Node<T> *curr = head;
    while (curr != nullptr) {
      if (curr->data == valToFind) {
        return true;
      }
      curr = curr->next;
    }
    return false;
  }

  // Reverse linked list
  Node<T> *reverseList() {
    Node<T> *prev = nullptr;
    Node<T> *curr = head;
    Node<T> *next_node = nullptr;

    while (curr != nullptr) {
      next_node = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next_node;
    }
    head = prev;
    return head;
  }

  /*
  find the middle of the linked list
  */
  Node<T> *findMiddle() const {
    if (head == nullptr) {
      return nullptr;
    }
    Node<T> *slow_ptr = head;
    Node<T> *fast_ptr = head;
    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
  }

  // print list
  void printList() const {
    Node<T> *current = head;
    std::cout << "List: ";
    while (current != nullptr) {
      std::cout << current->data << "-> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }
};

int main() {
  // In main()
  std::cout << "\n--- Find Middle Demo ---" << std::endl;
  SinglyLinkedList<int> mid_list_odd;
  mid_list_odd.insertAtEnd(1);
  mid_list_odd.insertAtEnd(2);
  mid_list_odd.insertAtEnd(3);
  mid_list_odd.insertAtEnd(4);
  mid_list_odd.insertAtEnd(5);
  mid_list_odd.printList(); // List: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
  Node<int> *middle_odd = mid_list_odd.findMiddle();
  if (middle_odd) {
    std::cout << "Middle node (odd): " << middle_odd->data
              << std::endl; // Expected: 3
  }

  SinglyLinkedList<int> mid_list_even;
  mid_list_even.insertAtEnd(10);
  mid_list_even.insertAtEnd(20);
  mid_list_even.insertAtEnd(30);
  mid_list_even.insertAtEnd(40);
  mid_list_even.printList(); // List: 10 -> 20 -> 30 -> 40 -> nullptr
  Node<int> *middle_even = mid_list_even.findMiddle();
  if (middle_even) {
    std::cout << "Middle node (even): " << middle_even->data
              << std::endl; // Expected: 30
  }

  return 0;
}