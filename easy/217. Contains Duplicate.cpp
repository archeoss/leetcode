/*
    217. Contains Duplicate

    Given an integer array nums, return true if any value appears at least twice
   in the array, and return false if every element is distinct.

    Example 1:

    Input: nums = [1,2,3,1]
    Output: true

    Example 2:

    Input: nums = [1,2,3,4]
    Output: false

    Example 3:

    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true
*/

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> used_nums;
    bool res = true;
    int num;
    for (int i = 0; res && i < nums.size(); i++) {
      num = nums[i];
      if (used_nums.count(num)) {
        res = false;
      } else {
        used_nums.insert(num);
      }
    }

    return !res;
  }
};
