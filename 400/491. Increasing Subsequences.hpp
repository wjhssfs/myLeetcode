// 491. Increasing Subsequences
// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
// Note:
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(nums, 0, result, results);
        return results;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int> &result, vector<vector<int>> &results) {
        unordered_set<int> m;
        for (int i = start; i < nums.size(); ++i) {
            if (m.count(nums[i])) continue;
            m.insert(nums[i]);
            if (result.empty() || nums[i] >= result.back()) {
                result.push_back(nums[i]);
                if (result.size() > 1) {
                    results.emplace_back(result);
                }  
                dfs(nums, i + 1, result, results);
                result.pop_back();
            }
        }
    }
};

public class Solution {

     public List<List<Integer>> findSubsequences(int[] nums) {
         Set<List<Integer>> res= new HashSet<List<Integer>>();
         List<Integer> holder = new ArrayList<Integer>();
         findSequence(res, holder, 0, nums);
         List result = new ArrayList(res);
         return result;
     }

    public void findSequence(Set<List<Integer>> res, List<Integer> holder, int index, int[] nums) {
        if (holder.size() >= 2) {
            res.add(new ArrayList(holder));
        }
        for (int i = index; i < nums.length; i++) {
            if(holder.size() == 0 || holder.get(holder.size() - 1) <= nums[i]) {
                holder.add(nums[i]);
                findSequence(res, holder, i + 1, nums);
                holder.remove(holder.size() - 1);
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<2) return ans;
        int fst[nums.size()];       //first
        bool rep[nums.size()];      //repeat
        for(int i=0;i<nums.size();++i){
            fst[i]=ans.size();
            rep[i]=false;
            for(int j=i-1;j>=0;--j){
                if(nums[j]<=nums[i]){
                    if(!rep[j]){
                        ans.emplace_back(vector<int>(2,nums[i]));
                        ans.back()[0]=nums[j];
                    }
                    for(int k=fst[j];k<fst[j+1];++k){
                        ans.push_back(ans[k]);
                        ans.back().emplace_back(nums[i]);
                    }
                    if(nums[j]==nums[i]){
                        rep[i]=true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};