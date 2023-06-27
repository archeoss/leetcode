/*
    35. Search Insert Position

    Given a sorted array of distinct integers and a target value, return the
   index if the target is found. If not, return the index where it would be if
   it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [1,3,5,6], target = 5
    Output: 2

    Example 2:

    Input: nums = [1,3,5,6], target = 2
    Output: 1

    Example 3:

    Input: nums = [1,3,5,6], target = 7
    Output: 4
*/

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    long begin = 0, end = nums.size(), mid = -1, num, res;
    while (begin < end) {
      mid = (end + begin) / 2;
      num = nums[mid];
      if (num == target) {
        res = mid;
        break;
      } else if (num < target) {
        res = mid + 1;
        begin = mid + 1;
      } else {
        res = end - 1;
        end = mid;
      }
    }

    return res;
  }
};
