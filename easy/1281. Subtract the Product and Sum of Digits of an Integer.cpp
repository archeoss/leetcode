/*
  1281. Subtract the Product and Sum of Digits of an Integer

  Given an integer number n, return the difference between the product of its
  digits and the sum of its digits.
*/

class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        int product = 1, sum = 0;
        while (n)
        {
            int num = n % 10;
            product *= num;
            sum += num;
            n = n / 10;
        }
        
        return product - sum;
    }
};
