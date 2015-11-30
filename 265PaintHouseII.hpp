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