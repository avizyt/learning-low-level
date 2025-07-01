#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Create a dummy node. This node simplifies handling the head of the merged
    // list. Its 'next' will eventually point to the actual head of the merged
    // list.
    ListNode *dummy = new ListNode();
    // 'tail' pointer will always poitn to the last node in our merged list.
    ListNode *tail = dummy;

    // loop as long as both lists have nodes to compare
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }
      tail = tail->next;
    }

    // attached the rest of the list
    if (list1 != nullptr) {
      tail->next = list1;
    } else if (list2 != nullptr) {
      tail->next = list2;
    }

    ListNode *mergedHead = dummy->next;

    delete dummy;
    dummy = nullptr;
    return mergedHead;
  }
};

// --- Helper functions for testing (not part of LeetCode solution) ---

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

// --- Main function for testing ---
int main() {
  Solution sol;

  // Test Case 1: Example from LeetCode
  std::cout << "Test Case 1:" << std::endl;
  ListNode *list1_1 = createList({1, 2, 4});
  ListNode *list2_1 = createList({1, 3, 4});
  std::cout << "List 1: ";
  printList(list1_1);
  std::cout << "List 2: ";
  printList(list2_1);
  ListNode *merged1 = sol.mergeTwoLists(list1_1, list2_1);
  std::cout << "Merged: ";
  printList(merged1);  // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr
  deleteList(merged1); // Free memory

  std::cout << "\nTest Case 2: Empty lists" << std::endl;
  ListNode *list1_2 = createList({});
  ListNode *list2_2 = createList({});
  std::cout << "List 1: ";
  printList(list1_2);
  std::cout << "List 2: ";
  printList(list2_2);
  ListNode *merged2 = sol.mergeTwoLists(list1_2, list2_2);
  std::cout << "Merged: ";
  printList(merged2);  // Expected: nullptr
  deleteList(merged2); // Free memory

  std::cout << "\nTest Case 3: One empty list" << std::endl;
  ListNode *list1_3 = createList({});
  ListNode *list2_3 = createList({0});
  std::cout << "List 1: ";
  printList(list1_3);
  std::cout << "List 2: ";
  printList(list2_3);
  ListNode *merged3 = sol.mergeTwoLists(list1_3, list2_3);
  std::cout << "Merged: ";
  printList(merged3);  // Expected: 0 -> nullptr
  deleteList(merged3); // Free memory

  std::cout << "\nTest Case 4: Longer lists, one ends first" << std::endl;
  ListNode *list1_4 = createList({5, 7, 9});
  ListNode *list2_4 = createList({1, 2, 3, 6, 8, 10});
  std::cout << "List 1: ";
  printList(list1_4);
  std::cout << "List 2: ";
  printList(list2_4);
  ListNode *merged4 = sol.mergeTwoLists(list1_4, list2_4);
  std::cout << "Merged: ";
  printList(merged4); // Expected: 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->
                      // nullptr
  deleteList(merged4); // Free memory

  return 0;
}