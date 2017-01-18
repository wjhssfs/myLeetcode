// 31 Next Permutation 
// Implement next permutation, which rearranges numbers into the lexicographically next
// greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding
// outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i-1]) i--;
        reverse(num.begin() + i, num.end());
        if (i == 0) return;
        int j = i;
        while (j < num.size() && num[j] <= num[i-1]) j++;
        swap(num[j], num[i-1]);
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &num) 
    {
        if (num.empty()) return;

        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = num.size()-2; i >= 0; --i)
        {
            if (num[i] < num[i+1]) break;
        }

        // reverse all the numbers after violated number
        reverse(begin(num)+i+1, end(num));
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(begin(num)+i+1, end(num), num[i]);
        // swap them, done!
        swap(num[i], *itr);
    }
};