/*
  974. Subarray Sums Divisible by K

  Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
  A subarray is a contiguous part of an array.

  Example 1:

  Input: nums = [4,5,0,-2,-3,1], k = 5
  Output: 7
  Explanation: There are 7 subarrays with a sum divisible by k = 5:
  [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

  Example 2:

  Input: nums = [5], k = 9
  Output: 0
*/
impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut groups = vec![0; k as usize];
        groups[0] = 1;
        let mut prefix_sum = 0;
        let mut res = 0;
        for num in nums {
            prefix_sum = (prefix_sum + num % k + k) % k;
            res += groups[prefix_sum as usize];
            groups[prefix_sum as usize] += 1;
        }

        res
    }
}

