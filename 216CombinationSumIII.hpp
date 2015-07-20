// 216 Combination Sum III 

// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Ensure that numbers within the set are sorted in ascending order.


// Example 1:

// Input: k = 3, n = 7

// Output:

// [[1,2,4]]

// Example 2:

// Input: k = 3, n = 9

// Output:

// [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> r;
        vector<int> cur;
        combinationSum3Helper(cur, 1, k, n, r);
        return r;
    }
    void combinationSum3Helper(vector<int> &cur, int start, int k, int n, vector<vector<int>> &r){
        if(!n && !k && !cur.empty()) r.push_back(cur);
        if(n < start || k <=0 || start > 9) return;
        combinationSum3Helper(cur, start + 1, k, n, r);
        cur.push_back(start);
        combinationSum3Helper(cur, start + 1, k - 1, n - start, r);
        cur.pop_back();
    }
};