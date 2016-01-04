// 315 Count of Smaller Numbers After Self
// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

// Example:

// Given nums = [5, 2, 6, 1]

// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Return the array [2, 1, 1, 0].

class Solution {
    vector<int> tree;
    int MaxVal;
    int read(int idx){
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    void update(int idx ,int val){
        while (idx <= MaxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        int n = (int)nums.size();
        if(!n) return result;
        result.resize(n);
        int minElem = INT_MAX, maxElem = INT_MIN;
        for(int i : nums) {minElem = min(minElem, i); maxElem = max(maxElem, i);}
        MaxVal = maxElem - minElem + 1;
        tree.resize(MaxVal+1);
        for(int i = n-1; i >= 0; i--){
            int normalizedI = nums[i]-minElem+1;
            result[i] = read(normalizedI-1);
            update(normalizedI, 1);
        }
        return result;
    }
};