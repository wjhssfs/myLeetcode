// 930. Binary Subarrays With Sum
// In an array A of 0s and 1s, how many non-empty subarrays have sum S?

// Example 1:

// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
 

// Note:

// A.length <= 30000
// 0 <= S <= A.length
// A[i] is either 0 or 1.

// missed S == 0, used A.size() instead of d.size(), returned wrong var
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if (S < 0) return 0;
        vector<int> d;
        d.push_back(-1);
        for (int i = 0; i < A.size(); ++i) if (A[i]) d.push_back(i);
        d.push_back(A.size());
        int right = S + 1, sum = 0;
        while (right < d.size()) {
            int left = right - S - 1;
            if (S == 0) sum += (d[right] - d[left] - 1) * (d[right] - d[left]) / 2;
            else sum += (d[right] - d[right - 1]) * (d[left+1] - d[left]);
            ++right;
        }
        return sum;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> sumCount {{0, 1}};
        int sum = 0, res = 0;
        for (auto a : A) {
            sum += a;
            res += sumCount[sum - S];
            sumCount[sum]++;
        }
        return res;
    }
};