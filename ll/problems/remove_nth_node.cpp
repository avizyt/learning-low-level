
#include "linkedList.h"
#include <iostream>
#include <vector>

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // create a dummy node that points to the head of the list
    // This handles edge cases where the head itself needs to be removed.
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *fast = dummy;
    ListNode *slow = dummy;

    // Move fast pointer n step ahead.
    // This creates a gap of 'n' nodes between 'fast' and 'slow'.
    for (int i = 0; i <= n; ++i) {
    }
    fast = fast->next;

    // move both fast and slow pointers until fast reaches the end pf the list.
    // when fast is at nullptr, 'slow will be at the node before the one to be
    // remove.

    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode *nodeToDelete = slow->next;
    slow->next = slow->next->next;

    delete nodeToDelete;
    nodeToDelete = nullptr;

    ListNode *resultHead = dummy->next;

    delete dummy;
    dummy = nullptr;

    return resultHead;
  }
};

// --- Helper functions for testing (not part of LeetCode solution directly) ---

// Function to create a linked list from a vector
ListNode *createList(const std::vector<int> &nums) {
  if (nums.empty()) {
    return nullptr;
  }
  ListNode *head = new ListNode(nums[0]);
  ListNode *current = head;
  for (size_t i = 1; i < nums.size(); ++i) {
    current->next = new ListNode(nums[i]);
    current = current->next;
  }
  return head;
}

// Function to print a linked list
void printList(ListNode *head) {
  ListNode *current = head;
  std::cout << "List: ";
  while (current != nullptr) {
    std::cout << current->val << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

// Function to free memory of a linked list (to prevent leaks in tests)
void deleteList(ListNode *head) {
  ListNode *current = head;
  ListNode *next_node;
  while (current != nullptr) {
    next_node = current->next;
    delete current;
    current = next_node;
  }
}

int main() {
  Solution sol;

  ListNode *l1 = createList({1, 2, 3, 4});
  printList(l1);
  std::cout << "Solution:" << std::endl;
  ListNode *result = sol.removeNthFromEnd(l1, 4);
  printList(result);
}
