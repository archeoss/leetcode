/*
 1491. Average Salary Excluding the Minimum and Maximum Salary

You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
 */

impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let (mut min, mut max) = (salary[0], salary[0]);
        let mut s = 0;
        for sal in &salary {
            if (*sal > max) {
                max = *sal;
            } else if (*sal < min) {
                min = *sal;
            }
            s += sal;
        }

        ((s - min - max) as f64 / (salary.len() - 2) as f64)
    }
}
