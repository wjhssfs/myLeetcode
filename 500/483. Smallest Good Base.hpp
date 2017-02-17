// 483. Smallest Good Base
// For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

// Now given a string representing n, you should return the smallest good base of n in string format. 

// Example 1:
// Input: "13"
// Output: "3"
// Explanation: 13 base 3 is 111.
// Example 2:
// Input: "4681"
// Output: "8"
// Explanation: 4681 base 8 is 11111.
// Example 3:
// Input: "1000000000000000000"
// Output: "999999999999999999"
// Explanation: 1000000000000000000 base 999999999999999999 is 11.
// Note:
// The range of n is [3, 10^18].
// The string representing n is always valid and will not have leading zeros.

// https://discuss.leetcode.com/topic/76368/python-solution-with-detailed-mathematical-explanation-and-derivation/2
class Solution {
    typedef unsigned long long ull;
public:
    string smallestGoodBase(string n) {
        ull num = (ull)stoll(n);
        int maxlen = log(num)/log(2)+1;
        for(int k=maxlen; k>=3; --k){
            ull b = pow(num,1.0/(k-1)), sum = 1, cur = 1;
            for (int i=1; i<k; ++i) 
                sum += (cur *= b);
            if(sum == num)
                return to_string(b);
        }  
        return to_string(num-1);
    }
};

class Solution {
public:
	string smallestGoodBase(string n) {
		unsigned long long tn = stoull(n), x = 1;
		for (int i = 60; i >= 1; i--) {
			if ((x << i)<tn) {
				unsigned long long cur = mysolve(tn, i);
				if (cur != 0) return to_string(cur);
			}
		}
		return to_string(tn - 1);
	}

	unsigned long long mysolve(unsigned long long n, int d) {
		double tn = (double)n;
		unsigned long long right = (unsigned long long)(pow(tn, 1.0 / d) + 1);
		unsigned long long left = 2;
		while (left <= right) {
			unsigned long long mid = left + (right - left) / 2;
			unsigned long long sum = 1, cur = 1;
			for (int i = 1; i <= d; i++) {
				cur *= mid;
				sum += cur;
			}
			if (sum == n) return mid;
			if (sum>n) right = mid - 1;
			else left = mid + 1;
		}
		return 0;
	}
};