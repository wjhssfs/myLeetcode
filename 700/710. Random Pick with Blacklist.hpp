// 710. Random Pick with Blacklist

// Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.

// Optimize it such that it minimizes the call to system’s Math.random().

// Note:

// 1 <= N <= 1000000000
// 0 <= B.length < min(100000, N)
// [0, N) does NOT include N. See interval notation.
// Example 1:

// Input: 
// ["Solution","pick","pick","pick"]
// [[1,[]],[],[],[]]
// Output: [null,0,0,0]
// Example 2:

// Input: 
// ["Solution","pick","pick","pick"]
// [[2,[]],[],[],[]]
// Output: [null,1,1,1]
// Example 3:

// Input: 
// ["Solution","pick","pick","pick"]
// [[3,[1]],[],[],[]]
// Output: [null,0,0,2]
// Example 4:

// Input: 
// ["Solution","pick","pick","pick"]
// [[4,[2]],[],[],[]]
// Output: [null,1,3,1]
// Explanation of Input Syntax:

// The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

// https://leetcode.com/problems/random-pick-with-blacklist/discuss/144624/Java-O(B)-O(1)-HashMap
class Solution {
    unordered_map<int, int> m;
    int M;
public:
    Solution(int N, vector<int> blacklist) {
        for (auto b : blacklist) m[b] = -1;
        M = N - m.size();
        for (auto b : blacklist) {
            if (b < M) {
                while (m.count(N - 1)) --N;
                m[b] = N - 1;
                --N;
            }
        }
        srand(time(0));
    }
    
    int pick() {
        int next = rand() % M;
        while (m.count(next)) next = m[next];
        return next;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

class Solution {
public:

    unordered_map<int, int> m;
    int wlen;

	Solution(int n, vector<int> b) {
        wlen = n - b.size();
        unordered_set<int> w;
        for (int i = wlen; i < n; i++) w.insert(i);
        for (int x : b) w.erase(x);
        auto wi = w.begin();
        for (int x : b)
            if (x < wlen)
                m[x] = *wi++;
	}

	int pick() {
        int k = rand() % wlen;
		return m.count(k) ? m[k] : k;
	}
};



// https://leetcode.com/articles/random-pick-with-blacklist/
class Solution {
	int n;
	vector<int> b;

public:

	Solution(int N, vector<int> blacklist) {
		n = N;
		sort(blacklist.begin(), blacklist.end());
		b = blacklist;
	}

	int pick() {
		int k = rand() % (n - b.size());
		int lo = 0;
		int hi = b.size() - 1;

		while (lo < hi) {
			int i = (lo + hi + 1) / 2;
			// b[i] - i = # of white list numbers
			if (b[i] - i > k) hi = i - 1;
			else lo = i;
		}
		return lo == hi && b[lo] - lo <= k ? k + lo + 1 : k;
	}
};