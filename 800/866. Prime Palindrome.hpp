// 866. Prime Palindrome
// Find the smallest prime palindrome greater than or equal to N.

// Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

// For example, 2,3,5,7,11 and 13 are primes.

// Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

// For example, 12321 is a palindrome.

 

// Example 1:

// Input: 6
// Output: 7
// Example 2:

// Input: 8
// Output: 11
// Example 3:

// Input: 13
// Output: 101

class Solution {
    int NP(int n) {
        string a = to_string(n);
        for (int l = 0, r = (int)a.size() - 1; l < r; ++l, --r) a[r] = a[l];
        int b = stoi(a);
        if (b > n) return b;
        string firstPart = to_string(stoi(a.substr(0, (a.size() - 1) / 2 + 1)) + 1);
        string c = firstPart + a.substr(1 + (a.size() - 1) / 2);
        for (int l = 0, r = (int)c.size() - 1; l < r; ++l, --r) c[r] = c[l];
        return stoi(c);
    }
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) return num == 2;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
    bool isPalindrome(int N) {
        string a = to_string(N);
        for (int l = 0, r = a.size() - 1; l <= r; l++, r--) {
            if (a[l] != a[r]) return false;
        } 

        return true;
    }
public:
    int primePalindrome(int N) {
        if (isPrime(N) && isPalindrome(N)) return N;
        while (1)
        {
            N = NP(N);            
            if (isPrime(N)) return N;
        }
    }
};

// https://leetcode.com/problems/prime-palindrome/discuss/146798/Search-Palindrome-with-Even-Digits
// All palindrome with even digits is multiple of 11. This means we only consider palindrome with odd digits.
class Solution {
    int primePalindrome(int N) {
        if (8 <= N && N <= 11) return 11;
        for (int x = 1; x < 100000; ++x) {
            string s = to_string(x), r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if (y >= N && isPrime(y)) return y;
        }
        return -1;
    }
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) return num == 2;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
}；