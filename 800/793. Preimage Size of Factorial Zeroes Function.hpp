// 793. Preimage Size of Factorial Zeroes Function
// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)

// For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has 2 zeroes at the end. Given K, find how many non-negative integers x have the property that f(x) = K.

// Example 1:
// Input: K = 0
// Output: 5
// Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.

// Example 2:
// Input: K = 5
// Output: 0
// Explanation: There is no x such that x! ends in K = 5 zeroes.
// Note:

// K will be an integer in the range [0, 10^9].

// First the answer is either 0 or 5 without doubt.
// Let x = a0 * 5^0 + a1 * 5^1 + a2 * 5^2 + … where a0, a1, a2 … are less than 5 and greater or equal to 0.

// Then f(x) = x / 5 + x / 5^2 + x / 5^3 + …
// = a1 * 1 + a2 * (1 + 5) + a3 * (1 + 5 + 5^2) + …
// = a1 * sum[0] + a2 * sum[1] + a3 * sum[2] + … as in the code above

// So if any one of the a above is not [0, 4] for a given number K, it violate the constraints so we should return 0.
// Otherwise return 5.

class Solution {
public:
    int preimageSizeFZF(int K) {
        int sum[13]={1};
        for (int i=1; i<13; i++) sum[i]=sum[i-1]*5+1;
        for (int i=12; i>=0; i--) {
            if (K/sum[i]==5) return 0;
            K=K%sum[i];
        }
        return 5;
    }
};

class Solution {
public:
    int preimageSizeFZF(int K) {
        long long lo = 0, hi = 5LL * K; // (5K)! has more than K zeros
		bool hasNumber = false;
		while (lo <= hi) {
			long long mid = lo + (hi - lo) / 2;
			long long cc = count(mid);
			if (cc < K) {
				lo = mid + 1;
			} else if (cc > K) {
				hi = mid - 1;
			} else {
				hasNumber = true;
				break;
			}
		}
		return hasNumber ? 5 : 0;
	}
	long long count(long long n) {
		if (n == 0)
			return 0;
		return n / 5 + count(n / 5);
    }
};
