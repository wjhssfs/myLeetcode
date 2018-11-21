// 788. Rotated Digits
// X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X. A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number.

// Now given a positive number N, how many numbers X from 1 to N are good?

// Example:
// Input: 10
// Output: 4
// Explanation: 
// There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
// Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
// Note:

// N  will be in range [1, 10000].

// https://leetcode.com/problems/rotated-digits/discuss/117975/Java-dp-solution-9ms
// dp[i] = 0, invalid number
// dp[i] = 1, valid and same number
// dp[i] = 2, valid and different number
   public int rotatedDigits(int N) {
        int[] dp = new int[N + 1];
        int count = 0;
        for(int i = 0; i <= N; i++){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9){
                    dp[i] = 2;
                    count++;
                }
            } else {
                int a = dp[i / 10], b = dp[i % 10];
                if(a == 1 && b == 1) dp[i] = 1;
                else if(a >= 1 && b >= 1){
                    dp[i] = 2;
                    count++;
                }
            }
        }
        return count;
    }

class Solution {
    bool isgood(int n) {
        string s = to_string(n);
        string t;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0' || s[i] == '1' || s[i] == '8') t += s[i];
            else if (s[i] == '2') t += '5';
            else if (s[i] == '5') t += '2';
            else if (s[i] == '6') t += '9';
            else if (s[i] == '9') t+= '6';
            else return false;
        }
        return t != s;
    }
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            if (isgood(i)) ++res;
        }
        return res;
    }
};

class Solution {
    public int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i ++) {
            if (isValid(i)) count ++;
        }
        return count;
    }
    
    public boolean isValid(int N) {
        /*
         Valid if N contains ATLEAST ONE 2, 5, 6, 9
         AND NO 3, 4 or 7s
         */
        boolean validFound = false;
        while (N > 0) {
            if (N % 10 == 2) validFound = true;
            if (N % 10 == 5) validFound = true;
            if (N % 10 == 6) validFound = true;
            if (N % 10 == 9) validFound = true;
            if (N % 10 == 3) return false;
            if (N % 10 == 4) return false;
            if (N % 10 == 7) return false;
            N = N / 10;
        }
        return validFound;
    }
}

class Solution {
    private int[] allPossibleCount = new int[]  {1,    2,    3,    3,    3,    4,    5,    5,    6,   7};       // 0,1,2,5,6,8,9
    private int[] excludeNumCount = new int[]   {1,    2,    2,    2,    2,    2,    2,    2,    3,   3};       // 0, 1, 8
    private boolean[] isValid = new boolean[]   {true, true, true, false,false,true, true, false,true,true};    // 0,1,2,5,6,8,9
    private boolean[] isExclude = new boolean[] {true, true, false,false,false,false,false,false,true,false};   // 0,1,8
    
    public int rotatedDigits(int N) {
        char[] cs = Integer.toString(N).toCharArray();
        int len = cs.length, count = 0;
        boolean exclude = true;
        int base7 = (int) Math.pow (7, len - 1), base3 = (int) Math.pow (3, len - 1);
        for (int i = 0; i < len; i++, base7 /= 7, base3 /= 3) {
            if (cs[i] == '0' && i != len - 1) continue;
            int index = i == len - 1 ? cs[i] - '0' : cs[i] - '0' - 1;
            double c = allPossibleCount[index] * base7;
            double e = exclude ? excludeNumCount[index] * base3 : 0; // # of numbers which only contain 0,1,8
            count += c - e;
            if (!isValid[cs[i] - '0']) break;
            exclude = exclude & isExclude[cs[i] - '0'];
        }
        return count;
    }
}