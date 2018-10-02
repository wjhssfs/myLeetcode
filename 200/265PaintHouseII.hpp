// 265 Paint House II

// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

// Note:
// All costs are positive integers.

// Follow up:
// Could you solve it in O(nk) runtime?

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(!costs.size()) return 0;
        auto minC(costs);
        for(int i = 1; i < minC.size(); i++){
            auto r = findMins(minC[i-1]);
            for(int j = 0; j < minC[0].size(); j++){
                minC[i][j] = r[j] + costs[i][j];
            }
        }
        
        return *min_element(minC.back().begin(), minC.back().end());
    }
private:
    vector<int> findMins(vector<int>&nums){
        vector<int> minFromFront(nums.size(), INT_MAX);
        vector<int> result(nums.size());
        minFromFront[0] = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            minFromFront[i] = min(minFromFront[i-1], nums[i-1]);
        }
        int minFromBack = INT_MAX;
        for(int i = (int)nums.size()-1; i >=0; i--){
            result[i] = min(minFromBack, minFromFront[i]);
            minFromBack = min(minFromBack, nums[i]);
        }
        return result;
    }
};


// https://leetcode.com/discuss/54415/ac-java-solution-without-extra-space
// The idea is similar to the problem Paint House I, for each house and each color,
// the minimum cost of painting the house with that color should be the minimum cost of painting previous houses,
// and make sure the previous house doesn't paint with the same color.
// We can use min1 and min2 to track the indices of the 1st and 2nd smallest cost till previous house,
// if the current color's index is same as min1, then we have to go with min2, otherwise we can safely go with min1.
public int minCostII(int[][] costs) {
    if (costs == null || costs.length == 0) return 0;

    int n = costs.length, k = costs[0].length;
    // min1 is the index of the 1st-smallest cost till previous house
    // min2 is the index of the 2nd-smallest cost till previous house
    int min1 = -1, min2 = -1;

    for (int i = 0; i < n; i++) {
        int last1 = min1, last2 = min2;
        min1 = -1; min2 = -1;

        for (int j = 0; j < k; j++) {
            if (j != last1) {
                // current color j is different to last min1
                costs[i][j] += last1 < 0 ? 0 : costs[i - 1][last1];
            } else {
                costs[i][j] += last2 < 0 ? 0 : costs[i - 1][last2];
            }

            // find the indices of 1st and 2nd smallest cost of painting current house i
            if (min1 < 0 || costs[i][j] < costs[i][min1]) {
                min2 = min1; min1 = j;
            } else if (min2 < 0 || costs[i][j] < costs[i][min2]) {
                min2 = j;
            }
        }
    }

    return costs[n - 1][min1];
}

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        auto dp = costs[0];
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            int last1 = min1, last2 = min2;
            min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                int validMin = dp[j] == last1 ? last2 : last1;
                if (validMin == INT_MAX) validMin = 0;
                dp[j] = validMin + costs[i][j];
                if (dp[j] <= min1) {
                    min2 = min1; min1 = dp[j];
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }
        }
        return min1;
    }
};