/*
    1. Two Sum

    Given an array of integers nums and an integer target, return indices of the
   two numbers such that they add up to target. You may assume that each input
   would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]

    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]
*/

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> used_nums;
    vector<int> res = {-1, -1};
    int num;
    for (int i = 0; i < nums.size(); i++) {
      num = nums[i];
      auto it = used_nums.find(target - num);
      if (it != used_nums.end()) {
        res = {used_nums[target - nums[i]], i};
        break;
      }
      used_nums[num] = i;
    }

    return res;
  }
};
