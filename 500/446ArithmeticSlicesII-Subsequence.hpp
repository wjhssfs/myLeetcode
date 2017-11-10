// 446. Arithmetic Slices II - Subsequence
// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
// For example, these are arithmetic sequences:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.
// 1, 1, 2, 5, 7
// A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
// A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.
// The function should return the number of arithmetic subsequence slices in the array A.
// The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.
// Example:
// Input: [2, 4, 6, 8, 10]
// Output: 7
// Explanation:
// All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]

// https://discuss.leetcode.com/topic/67413/detailed-explanation-for-java-o-n-2-solution/2
// As a rule of thumb, when there is difficulty relating original problem to its subproblems,
// it usually indicates something goes wrong with your formulation for the original problem.
// res is the final count of all valid arithmetic subsequence slices; map will store the intermediate results T(i, d), 
// with i indexed into the array and d as the key of the corresponding HashMap.
// For each index i, we find the total number of "generalized" arithmetic subsequence slices ending at it with all possible differences.
// This is done by attaching A[i] to all slices of T(j, d) with j less than i.
// Within the inner loop, we first use a long variable diff to filter out invalid cases, then get the counts of all valid slices (with element >= 3) as c2 and
// add it to the final count. At last we update the count of all "generalized" slices for T(i, d) by adding the three parts together:
// the original value of T(i, d), which is c1 here, the counts from T(j, d), which is c2 and lastly the 1 count of the "two-element" slice (A[j], A[i]).
public int numberOfArithmeticSlices(int[] A) {
    int res = 0;
    Map<Integer, Integer>[] map = new Map[A.length];
        
    for (int i = 0; i < A.length; i++) {
        map[i] = new HashMap<>(i);
            
        for (int j = 0; j < i; j++) {
            long diff = (long)A[i] - A[j];
            if (diff <= Integer.MIN_VALUE || diff > Integer.MAX_VALUE) continue;
                
            int d = (int)diff;
            int c1 = map[i].getOrDefault(d, 0);
            int c2 = map[j].getOrDefault(d, 0);
            res += c2;
            map[i].put(d, c1 + c2 + 1);
        }
    }
        
    return res;
}

// 256 ms
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = (int)A.size(), total = 0;
        unordered_map<int, map<int, int>> m; // expect, diff, count
        unordered_set<int> s(A.begin(), A.end());
        for (int i = 1; i < sz; ++i) {
            if (m.count(A[i])) {
                for (auto &r : m[A[i]]) {
                    total += r.second;
                    long long expect = (long long)A[i] + r.first;
                    if (expect < INT_MIN || expect > INT_MAX) continue;
                    m[A[i] + r.first][r.first] += r.second;
                }
            }
            for (int j = 0; j < i; ++j) {
                long long diff = (long long) A[i] - A[j];
                long long expect = diff + A[i];
                if (diff < INT_MIN || diff > INT_MAX || expect < INT_MIN || expect > INT_MAX) continue;
                if (!s.count((int)expect)) continue;
                ++m[(int)expect][(int)diff];
            }
        }
        return total;
    }
};
// 1495 ms
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		vector<unordered_map<long long, int>> m(A.size());
		int total = 0;
		for (int i = 1; i < A.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				long long diff = (long long)A[i] - A[j];
				if (diff < INT_MIN || diff > INT_MAX) continue;
				++m[i][diff];
				if (m[j].count(diff)) {
					total += m[j][diff];
					m[i][diff] += m[j][diff];
				}
			}
		}
		return total;
	}
};