/*
   918. Maximum Sum Circular Subarray

   Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
   A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
   A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

   Example 1:

   Input: nums = [1,-2,3,-2]
   Output: 3
   Explanation: Subarray [3] has maximum sum 3.

   Example 2:

   Input: nums = [5,-3,5]
   Output: 10
   Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

   Example 3:

   Input: nums = [-3,-2,-3]
   Output: -2
   Explanation: Subarray [-2] has maximum sum -2.
*/

impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        let (mut cur_max, mut cur_min, mut sum, mut max_sum, mut min_sum) =
            (0, 0, 0, nums[0], nums[0]);
        for num in nums {
            cur_max = cur_max.max(0) + num;
            max_sum = max_sum.max(cur_max);
            cur_min = cur_min.min(0) + num;
            min_sum = min_sum.min(cur_min);
            sum += num;
        }

        if sum == min_sum {
            max_sum
        } else {
            max_sum.max(sum - min_sum)
        }
    }
}
