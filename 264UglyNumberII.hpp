// 264 Ugly Number II

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note that 1 is typically treated as an ugly number.

// Hint:

// The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
// An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
// The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
// Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> ugly;
        ugly.insert(1);
        while(n){
            long long m = *ugly.begin();
            ugly.insert(m*2);
            ugly.insert(m*3);
            ugly.insert(m*5);
            ugly.erase(ugly.begin());
            --n;
            if(!n) return m;
        }
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> m(n);
        int p = 0, i = 0, j = 0, k = 0;
        m[p] = 1;
        while(--n){
            int next = min(m[i] * 2, min(m[j] * 3, m[k] * 5));
            // 3 ifs, this handles cases like next = 30, 
            // multiple indexes are increases
            if(next == m[i] * 2) i++;
            if(next == m[j] * 3) j++;
            if(next == m[k] * 5) k++;
            m[++p] = next;
        }
        return m[p];
    }
};