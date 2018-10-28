// 338. Counting Bits
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate
// the number of 1's in their binary representation and return them as an array.
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
// Follow up:
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
// Hint:
// You should make use of what you have produced already.
// Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
// Or does the odd/even status of the number help you in calculating the number of 1s?

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(1);
        while (ret.size() < num + 1) {
            int size = ret.size();
            for (int j = 0; j < size && ret.size() < num + 1; ++j) {
                ret.push_back(1 + ret[j]);
            }
        }
        return ret;
    }
};

// An easy recurrence for this problem is f[i] = f[i / 2] + i % 2.
public int[] countBits(int num) {
    int[] f = new int[num + 1];
    for (int i=1; i<=num; i++) f[i] = f[i >> 1] + (i & 1);
    return f;
}

class Solution {
public:
    vector<int> countBits(int num) {
        map<unsigned, unsigned> m;
        for (int i = 0; i < sizeof(int) * 8; ++i) m[1U << i] = i;
        vector<int> ret;
        ret.push_back(0);
        for (int i = 1; i <= num; ++i) ret.push_back(ret.back() - m[i & -i] + 1);
        return ret;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};


