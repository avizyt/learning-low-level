#include "linkedList.h"
#include <iostream>
#include <vector>

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next_node = nullptr;

    while (current != nullptr) {
      next_node = current->next;
      current->next = prev;
      prev = current;
      current = next_node;
    }
    // 'prev' is the new head of the reversed list
    return prev;
  }

  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    // Step 1: find the middle of the linked list
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *first_half_end_prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      first_half_end_prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *second_half_start;
    ListNode *first_half_end;

    // Detemine the start of the second half and the end of first half
    if (fast == nullptr) {
      second_half_start = slow;
      first_half_end = first_half_end_prev;
    } else {
      second_half_start = slow->next;
      first_half_end = slow;
    }

    // break the link between the first half and the second half
    // this makes the first half a standalone list ending in nullptr
    if (first_half_end) {
      first_half_end->next = nullptr;
    }

    // step 2 reverse the second half
    ListNode *second_half_reversed = reverseList(second_half_start);

    // step 3 compare the first half with the reversed second half
    ListNode *p1 = head;
    ListNode *p2 = second_half_reversed;

    bool is_palindrome = true;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val != p2->val) {
        is_palindrome = false;
        break;
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    // restore the original list structure
    ListNode *original_second_half = reverseList(second_half_reversed);

    if (first_half_end) {
      first_half_end->next = original_second_half;
    } else {
    }
    return is_palindrome;
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

// --- Main function for testing ---
int main() {
  Solution sol;

  // Test Case 1: Palindrome (even length)
  std::cout << "Test Case 1 (Palindrome Even):" << std::endl;
  ListNode *list1 = createList({1, 2, 2, 1});
  printList(list1);
  std::cout << "Is Palindrome? " << (sol.isPalindrome(list1) ? "true" : "false")
            << std::endl; // Expected: true
  // deleteList(list1); // Careful: isPalindrome modifies the list. Re-creating
  // for tests is safer if not restoring.

  // Test Case 2: Palindrome (odd length)
  std::cout << "\nTest Case 2 (Palindrome Odd):" << std::endl;
  ListNode *list2 = createList({1, 2, 3, 2, 1});
  printList(list2);
  std::cout << "Is Palindrome? " << (sol.isPalindrome(list2) ? "true" : "false")
            << std::endl; // Expected: true

  // Test Case 3: Not Palindrome
  std::cout << "\nTest Case 3 (Not Palindrome):" << std::endl;
  ListNode *list3 = createList({1, 2});
  printList(list3);
  std::cout << "Is Palindrome? " << (sol.isPalindrome(list3) ? "true" : "false")
            << std::endl; // Expected: false

  // Test Case 4: Single Node
  std::cout << "\nTest Case 4 (Single Node):" << std::endl;
  ListNode *list4 = createList({1});
  printList(list4);
  std::cout << "Is Palindrome? " << (sol.isPalindrome(list4) ? "true" : "false")
            << std::endl; // Expected: true

  // Test Case 5: Empty List
  std::cout << "\nTest Case 5 (Empty List):" << std::endl;
  ListNode *list5 = createList({});
  printList(list5);
  std::cout << "Is Palindrome? " << (sol.isPalindrome(list5) ? "true" : "false")
            << std::endl; // Expected: true

  // Test Case 6: Longer Not Palindrome
  std::cout << "\nTest Case 6 (Longer Not Palindrome):" << std::endl;
  ListNode *list6 = createList({1, 2, 3, 4, 5, 6});
  printList(list6);
  std::cout << "Is Palindrome? " << (sol.isPalindrome(list6) ? "true" : "false")
            << std::endl; // Expected: false

  // For rigorous testing, remember to manually delete the lists if you're not
  // putting them in smart pointers or if the problem solution itself doesn't
  // free them. For LeetCode, you don't typically manage memory in main, just in
  // the solution function if new nodes are created. Since we are modifying
  // existing nodes' next pointers, careful deletion logic would be needed here.
  // For simplicity of testing in main, I'm omitting deleteList calls after
  // isPalindrome because it modifies list structures.

  return 0;
}