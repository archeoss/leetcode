/*
    3. Longest Substring Without Repeating Characters

    Given a string s, find the length of the longest
    substring
    without repeating characters.

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
*/

use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map = HashMap::new();
        let mut res = 0;
        let mut left = 0;
        for (pos, ch) in s.chars().enumerate() {
            if let Some(&entry) = map.get(&ch) {
                res = res.max(pos - left);
                left = left.max(entry + 1);
            }
            map.insert(ch, pos);
        }

        res.max(s.len() - left) as i32
    }
}

// First Solution
// impl Solution {
//     pub fn length_of_longest_substring(s: String) -> i32 {
//         let mut map = HashMap::new();
//         let mut res = 0;
//         let mut cur_len = 0;
//         let (mut iter_left, iter_right) = (s.chars(), s.chars());
//         for ch in iter_right {
//             let entry = map.get(&ch);
//             if entry.is_some() && *entry.unwrap() {
//                 res = res.max(cur_len);
//                 for left_ch in iter_left.by_ref() {
//                     cur_len -= 1;
//                     map.insert(left_ch, false);
//                     if left_ch == ch {
//                         break;
//                     }
//                 }
//             }
//             cur_len += 1;
//             map.insert(ch, true);
//         }
//
//         res.max(cur_len)
//     }
// }
