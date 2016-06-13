// 18 4Sum 
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int N = num.size();
        vector<vector<int> > res;
        if (N < 4) return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < N; ++i)
        {
            if (i > 0 && num[i] == num[i-1]) continue; // avoid duplicates
            for (int j = i+1; j < N; ++j)
            {
                if (j > i+1 && num[j] == num[j-1]) continue; // avoid duplicates
                int twosum = target - num[i] - num[j];
                int l = j + 1, r = N - 1;
                while (l < r)
                {
                    int sum = num[l] + num[r];
                    if (sum == twosum) {
                        res.push_back({num[i], num[j], num[l], num[r]});
                        while (l < r && num[l+1] == num[l]) l++; // avoid duplicates
                        while (l < r && num[r-1] == num[r]) r--; // avoid duplicates
                        l++; r--;
                    }
                    else if (sum < twosum) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};