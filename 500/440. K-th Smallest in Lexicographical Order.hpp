// 440. K-th Smallest in Lexicographical Order
// Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

// Note: 1 ≤ k ≤ n ≤ 109.

// Example:

// Input:
// n: 13   k: 2

// Output:
// 10

// Explanation:
// The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

// https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination
class Solution {
public:
	int findKthNumber(int n, int k) {
		int cur = 1;
		--k;
		while (k) {
			int gap = findGapToNext(n, cur);
			if (gap <= k) {
				++cur;
				k -= gap;
			}
			else {
				cur *= 10;
				--k;
			}
		}
		return cur;
	}
private: 
	int findGapToNext(int n, long long cur) {
		int gap = 0, next = cur + 1;
		while (cur <= n) {
			gap += min(n + 1, next) - cur;
			cur *= 10;
			next *= 10;
		}
		return gap;
	}
};
