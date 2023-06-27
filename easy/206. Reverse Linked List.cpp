/*
    206. Reverse Linked List
    Given the head of a singly linked list, reverse the list, and return the
   reversed list.
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
  ListNode *reverseList(ListNode *head) {
    if (!head)
      return head;
    if (!head->next)
      return head;

    ListNode *newHead = new ListNode(head->next->val);
    ListNode *prevHead = head;
    ListNode *it = head->next->next;
    newHead->next = new ListNode(prevHead->val);
    prevHead = newHead;
    while (it) {
      newHead = new ListNode(it->val);
      it = it->next;
      newHead->next = new ListNode(prevHead->val, prevHead->next);
      prevHead = newHead;
    }

    return newHead;
  }
};
