// 15 3Sum 

// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > results;
		sort(num.begin(), num.end());
		int sz = num.size();
		for (int i = 0; i < sz - 2; i++){
			if (i>0&&num[i] == num[i - 1])continue;
			int j = i + 1, k = sz - 1, csum = num[i] + num[j] + num[k];
			while (j<k){
				if (csum <= 0){
					if (!csum)
						results.push_back({ num[i], num[j], num[k] });
					csum -= num[j];
					while(j<k && num[j]==num[j+1])j++;
					if(j<k) j++;
					csum += num[j];
				}
				else if (csum > 0){
					csum -= num[k];
					while(j<k && num[k]==num[k-1])k--;
					if(j<k) k--;
					csum += num[k];
				}
			}
		}
		return results;
	}
};

class Solution2 {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int N = num.size();
        for (int i = 0; i < N-2 && num[i] <= 0; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue; // avoid duplicates
            int twosum = 0 - num[i];
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int sum = num[l] + num[r];
                if (sum < twosum)
                    l++;
                else if (sum > twosum)
                    r--;
                else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[l]);
                    triplet.push_back(num[r]);
                    res.push_back(triplet);
                    l++; r--;
                    while (l < r && num[l] == num[l-1]) l++;  // avoid duplicates
                    while (l < r && num[r] == num[r+1]) r--;  // avoid duplicates
                }
            }
        }
        return res;
    }
};
