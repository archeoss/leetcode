struct Solution;
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let nums = vec![
            (1, "I"),
            (4, "IV"),
            (5, "V"),
            (9, "IX"),
            (10, "X"),
            (40, "XL"),
            (50, "L"),
            (90, "XC"),
            (100, "C"),
            (400, "CD"),
            (500, "D"),
            (900, "CM"),
            (1000, "M"),
        ];
        let mut num = num;
        let mut res = String::new();
        for pair in nums.iter().rev() {
            if num == 0 {
                break;
            }

            let times = num / pair.0;
            res += pair.1.repeat(times as usize).as_str();
            num -= pair.0 * times;
        }

        res
    }
}
fn main() {
    println!("Hello, world!");
}
