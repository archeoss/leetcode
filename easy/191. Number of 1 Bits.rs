/*
 191. Number of 1 Bits

 Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

 Example 1:

 Input: n = 00000000000000000000000000001011
 Output: 3
 Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*/

impl Solution {
    pub fn hammingWeight(mut n: u32) -> i32 {
        let mut res = 0;
        while (n != 0) {
            res += n & 1;
            n = n >> 1;
        }

        res as i32
    }
}
