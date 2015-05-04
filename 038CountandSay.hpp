// 38 Count and Say 
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n >= 0) {
            string st;
            int curNum = s[0];
            int cDup = 1;
            for (size_t i = 1; i <= s.size(); i++)
            {
                if (i < s.size() && s[i] == curNum) cDup++;
                else
                {
                    st += cDup + '0';
                    st += curNum;
                    curNum = s[i];
                    cDup = 1;
                }
            }
            s.swap(st);
        }
        return s;
    }
};

class Solution2 {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i)
        {
            stringstream ss;
            int j = 0, N = res.size();
            while (j < N) {
                int k = j + 1;
                while (k < N && res[k] == res[j])
                    k++;
                ss << (k - j) << res[j];
                j = k;
            }
            ss >> res;
        }
        return res;
    }
};
