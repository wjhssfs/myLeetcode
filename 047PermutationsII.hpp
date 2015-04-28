// 47 Permutations II 
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
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
    vector<vector<int>> permuteUnique(vector<int> &num) {
        res.clear();
        sort(num.begin(), num.end());
        bool avail[num.size()];
        memset(avail, true, sizeof(avail));
        vector<int> pum;
        permuteUniqueRe(num, pum, avail);
        return res;
    }

    void permuteUniqueRe(vector<int> &num, vector<int> &pum, bool avail[])
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        int last_index = -1;
        for (int i = 0; i < num.size(); ++i)
        {
            if (!avail[i]) continue;
            if (last_index != -1 && num[i] == num[last_index]) continue;
            
            avail[i] = false;
            pum.push_back(num[i]);
            permuteUniqueRe(num, pum, avail);
            pum.pop_back();
            avail[i] = true;
            last_index = i;
        }
    }
};

