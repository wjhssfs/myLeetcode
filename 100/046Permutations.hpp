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

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size() - 1) {
            // one permutation instance
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};

public List<List<Integer>> permute(int[] num) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    if (num.length ==0) return ans;
    List<Integer> l0 = new ArrayList<Integer>();
    l0.add(num[0]);
    ans.add(l0);
    for (int i = 1; i< num.length; ++i){
        List<List<Integer>> new_ans = new ArrayList<List<Integer>>(); 
        for (int j = 0; j<=i; ++j){            
           for (List<Integer> l : ans){
               List<Integer> new_l = new ArrayList<Integer>(l);
               new_l.add(j,num[i]);
               new_ans.add(new_l);
           }
        }
        ans = new_ans;
    }
    return ans;
}
