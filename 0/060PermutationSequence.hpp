// 60 Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
// Note: Given n will be between 1 and 9 inclusive.

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n < 1) return "";
        vector<int> c(n); set<int> s;
        string result;
        k--;
        c[0] = 1; s.insert(1);
        for (int i = 1; i < n; i++)
        {
            c[i] = c[i - 1] * (i+1);
            s.insert(i+1);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int m = 0;
            if (i == 0){
                m = 0;
            }
            else
            {
                m = k / c[i - 1];
                k -= m * c[i - 1];
            }
            auto it = s.begin();
            while (m--) it++;
            char nc = '0' + *it;
            result = result + nc;
            s.erase(it);
        }
        return result;
    }
};

class Solution2 {
public:
    string getPermutation(int n, int k) {
        string num, res;
        int total = 1;
        for (int i = 1; i <= n; ++i)
        {
            num.push_back(i + '0');
            total *= i;
        }
        k--;
        while (n)
        {
            total /= n;
            int i = k / total;
            k %= total;
            res.push_back(num[i]);
            num.erase(i, 1);
            n--;
        }
        return res;
    }
};
