/*
    234. Palindrome Linked List

    Given the head of a singly linked list, return true if it is a
    palindrome
    or false otherwise.

    Example 1:

    Input: head = [1,2,2,1]
    Output: true

    Example 2:

    Input: head = [1,2]
    Output: false
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *tmp;
  bool isPalindrome(ListNode *head) {
    tmp = head;

    return check(head);
  }

  bool check(ListNode *head) {
    if (head == nullptr) {
      return true;
    }
    bool res = check(head->next) & (tmp->val == head->val);
    tmp = tmp->next;

    return res;
  }
};
