// 229 Majority Element II  
// Given an integer array of size n, find all elements that appear more than n/3 times. The algorithm should run in linear time and in O(1) space.
// Hint:
// How many majority elements could it possibly have?

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;
        vector<int> res;
        for(auto n : nums) m[n]++;
        for(auto r : m) { if (r.second > nums.size()/3) res.push_back(r.first);}
        return res;
    }

    // http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
    // http://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
    // https://leetcode.com/discuss/43248/boyer-moore-majority-vote-algorithm-and-my-elaboration
    vector<int> majorityElement2(vector<int>& nums) {
        int cnt1=0, cnt2=0;
        int a,b;

        for(int n: nums){
            if (cnt1 == 0 || n == a){
                cnt1++;
                a = n;
            }
            else if (cnt2 == 0 || n==b){
                cnt2++;
                b = n;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=cnt2=0;
        for(int n: nums){
            if (n==a)   cnt1++;
            else if (n==b) cnt2++;
        }

        vector<int> result;
        if (cnt1 > nums.size()/3)   result.push_back(a);
        if (cnt2 > nums.size()/3)   result.push_back(b);
        return result;
    }
};

