/*
  1281. Subtract the Product and Sum of Digits of an Integer

  Given an integer number n, return the difference between the product of its
  digits and the sum of its digits.
*/

impl Solution {
    pub fn subtract_product_and_sum(mut n: i32) -> i32 {
        let (mut product, mut sum) = (1, 0);
        while n != 0 {
            let num = n % 10;
            product *= num;
            sum += num;
            n = n / 10;
        }

        product - sum
    }
}
