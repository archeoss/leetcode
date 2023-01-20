/*
 * 491. Non-decreasing Subsequences
 * Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
 *
 * Example 1:
 * Input: nums = [4,6,7,7]
 * Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 *
 * Example 2:
 * Input: nums = [4,4,3,2,1]
 * Output: [[4,4]]
 */
impl Solution {
    pub fn find_subsequences(nums: Vec<i32>) -> Vec<Vec<i32>> {
        use std::collections::HashSet;
        let mut res: HashSet<Vec<i32>> = HashSet::new();
        struct Rec<'s> {
            function: &'s dyn Fn(&Rec, &mut HashSet<Vec<i32>>, usize, &mut Vec<i32>),
        }
        let rec = Rec {
            function: &|rec, res, ind, cur_seq| {
                if ind == nums.len() {
                    if cur_seq.len() > 1 {
                        res.insert(cur_seq.clone());
                    }
                    return;
                } else {
                    if cur_seq.is_empty() || *cur_seq.last().unwrap() <= nums[ind] {
                        cur_seq.push(nums[ind]);
                        (rec.function)(rec, res, ind + 1, cur_seq);
                        cur_seq.pop();
                    }
                }
                (rec.function)(rec, res, ind + 1, cur_seq);
            },
        };
        (rec.function)(&rec, &mut res, 0, &mut Vec::new());

        res.into_iter().collect::<Vec<_>>()
    }
}
