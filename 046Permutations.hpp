// 46 Permutations 

// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ret;
		sort(num.begin(), num.end());
		do{
			ret.push_back(num);
		} while (nextPermute(num));
		return ret;
	}

	bool nextPermute(vector<int> &num){
		int sz = num.size();
		int a = -1, b = -1;
		for (int i = sz - 1; i>0; i--){
			if (num[i - 1]<num[i])  {
				a = i - 1;
				break;
			}
		}
		if (a == -1) return false;
		for (int i = sz - 1; i>a; i--){
			if (num[a]<num[i])  {
				b = i;
				break;
			}
		}
		swap(num[a], num[b]);
		for (int i = a + 1; i <= (a + 1 + sz - 1) / 2; i++){
			swap(num[i], num[sz - 1 - (i - a - 1)]);
		}
		return true;
	}
};

class Solution2 {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &num) {
        res.clear();
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        permuteRe(num, avail, pum);
        return res;
    }

    void permuteRe(const vector<int> &num, vector<bool> &avail, vector<int> &pum)
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (avail[i])
            {
                avail[i] = false;
                pum.push_back(num[i]);
                permuteRe(num, avail, pum);
                pum.pop_back();
                avail[i] = true;
            }
        }
    }
};
