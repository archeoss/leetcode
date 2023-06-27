/*
    242. Valid Anagram

    Given two strings s and t, return true if t is an anagram of s, and false
   otherwise. An Anagram is a word or phrase formed by rearranging the letters
   of a different word or phrase, typically using all the original letters
   exactly once.

    Example 1:

    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:

    Input: s = "rat", t = "car"
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
  bool isAnagram(string s, string t) {
    if (t.size() != s.size())
      return false;

    bool res = true;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<int, int> letters;
    for (int c : alphabet) {
      letters[c] = 0;
    }
    for (int c : s) {
      letters[c]++;
    }
    for (int i = 0; res && i < t.size(); i++) {
      int tmp = t[i];
      if (!letters[tmp]) {
        res = false;
      } else {
        letters[tmp]--;
      }
    }

    return res;
  }
};
