// 90 Subsets II 
// Given a collection of integers that might contain duplicates, mums, return all possible subsets.
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
        std::vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
    }
private:
    void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i) {
            if (i == begin || nums[i] != nums[i - 1]) { 
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i + 1);
                vec.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};