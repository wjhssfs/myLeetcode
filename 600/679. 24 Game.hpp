// 679. 24 Game

// You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

// Example 1:
// Input: [4, 1, 8, 7]
// Output: True
// Explanation: (8-4) * (7-1) = 24
// Example 2:
// Input: [1, 2, 1, 2]
// Output: False
// Note:
// The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
// Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
// You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if (valid(nums)) return true;
        } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
private:
    bool valid(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
        if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
        if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
        return false;
    }
    bool valid(double a, double b, double c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001) 
            return true;
        return false;
    }
};

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> numsCopy;
        for (auto n : nums) numsCopy.push_back(n);
        return dfs(numsCopy);
    }
private:
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) return abs(nums[0] - 24) < 0.05;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                vector<double> numsCopy;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k == i || k == j) continue;
                    numsCopy.push_back(nums[k]);
                }
                numsCopy.push_back(nums[i] + nums[j]);
                if (dfs(numsCopy)) return true;
                numsCopy.back() = (nums[i] - nums[j]);
                if (dfs(numsCopy)) return true;
                numsCopy.back() = (nums[i] * nums[j]);
                if (dfs(numsCopy)) return true;
                if (nums[j] != 0) {
                    numsCopy.back() = (nums[i] / nums[j]);
                    if (dfs(numsCopy)) return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        ops = {std::plus<double>(), std::minus<double>(), std::multiplies<double>(), std::divides<double>()};
        vector<double> numsCopy;
        for (auto n : nums) numsCopy.push_back(n);
        return dfs(numsCopy);
    }
private:
    vector<function<double(double, double)>> ops;
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) return abs(nums[0] - 24.0) < 0.05;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                vector<double> numsCopy;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k == i || k == j) continue;
                    numsCopy.push_back(nums[k]);
                }
                for (int k = 0; k < 4; ++k) {
                    if ((k == 0 || k == 2) && i > j) continue;
                    if (k == 3 && nums[j] == 0.0) continue;
                    numsCopy.push_back(ops[k](nums[i],nums[j]));
                    if (dfs(numsCopy)) return true;
                    numsCopy.pop_back();
                }
            }
        }
        return false;
    }
};


// https://discuss.leetcode.com/topic/103979/%EB%96%A2%EB%B8%BB%EA%B0%81%EA%B1%8E%EB%83%87%EA%B0%85%EA%B0%B8%EA%BA%9A%EB%B5%9F%EC%88%A3%EC%9A%84%EB%B5%B4%EB%B5%9E%EB%A4%BC%EA%B0%88%EA%B0%8C%EB%A4%94%EB%96%8C%EC%98%8A%EB%A9%94%EB%8A%84%EC%88%AD%EC%BA%B8%EA%B8%B6%EA%BA%9B%EC%98%96%EA%B0%8D%EB%87%90%EC%A9%A2%EA%B3%B4%EB%93%87%EA%B1%AF%EA%B6%84%EC%98%95%EC%99%B9%EB%88%9E%EC%86%B4%EA%B1%83%EB%81%97%EA%B8%AC%EB%95%89%EA%B6%BF%EA%B0%80%EC%8C%80%EB%82%90%EA%B1%84%EC%88%A4%EB%BA%B4%EB%8A%98%EA%B1%98%EA%BD%B8%EC%88%A2%EA%B1%82%EA%B0%8B%EA%B0%83%EC%AB%90%EA%BC%94%EC%86%BE%EC%A9%A1%EC%87%94%EC%86%BF%EB%81%9B%EB%A4%9C%EA%B0%84%EB%B8%BA%EC%A9%AC%EC%9B%A8%EB%94%B4%EC%98%A0%EB%A4%9B%EA%B0%82%EB%B5%AA%EB%8D%A0%EB%86%A4%EB%B9%90%EC%98%8B%EA%B7%92%EB%8A%82%EA%B0%B0%EA%B0%96%EB%86%A5%EA%B6%BE%EA%B0%86%EC%98%8C%EB%BC%98%EB%AC%B0%EA%B1%B0%EA%B0%8E%EA%B8%B7%EB%82%A4%EA%B2%BC

def judgePoint24(self, nums):
    bad = '떢븻각걎냇갅갸꺚뵟숣욄뵴뵞뤼갈갌뤔떌옊메늄숭캸긶꺛옖갍뇐쩢곴듇걯궄옕왹눞솴걃끗긬땉궿가쌀낐걄숤뺴늘걘꽸숢걂갋갃쫐꼔솾쩡쇔솿끛뤜간븺쩬웨딴옠뤛갂뵪덠놤빐옋귒늂갰갖놥궾갆옌뼘묰거갎긷낤겼'
    return chr(int(''.join(map(str, sorted(nums)))) + 42921) not in bad