// 343. Integer Break
// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
// Note: you may assume that n is not less than 2.
// Hint:
// There is a simple O(n) solution to this problem.
// You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

// https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem
// If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without losing optimality,
// as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4, meaning you only need factors 1, 2 and 3
// (and 1 is of course wasteful and you'd only use it for n=2 and n=3, where it's needed).

// https://discuss.leetcode.com/topic/45341/a-simple-explanation-of-the-math-part-and-a-o-n-solution
public class Solution {
    public int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product = 1;
        while(n>4){
            product*=3;
            n-=3;
        }
        product*=n;
        
        return product;
    }
}

public class Solution {
    public int integerBreak(int n) {
        if(n <= 3) return n-1; //assuming n >= 2
        return n%3 == 0 ? (int)Math.pow(3, n/3) : n%3 == 1 ? (int)Math.pow(3, n/3-1)*4 : (int)Math.pow(3, n/3)*2;
    }
}

public class Solution {
public int integerBreak(int n) {
    int[] dp = new int[n + 1];
   dp[1] = 1;
   for(int i = 2; i <= n; i ++) {
       for(int j = 1; 2*j <= i; j ++) {
           dp[i] = Math.max(dp[i], (Math.max(j,dp[j])) * (Math.max(i - j, dp[i - j])));
       }
   }
   return dp[n];
}
}