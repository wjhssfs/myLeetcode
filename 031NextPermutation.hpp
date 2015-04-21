// 31 Next Permutation 
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int sz = num.size();
        if (sz)
        {
            int i = sz - 1;
            for (; i >= 1; i--){
                if (num[i] > num[i - 1])
                {
                    break;
                }
            }
            if (i != 0)
            {
                int j = i;
                for (; j < sz-1; j++)
                {
                    if (num[j + 1] <= num[i - 1])
                    {
                        break;
                    }
                }
                swap(num[i - 1], num[j]);
            }

            reverse(num.begin() + i, num.end());
        }
    }
};

class Solution2 {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i-1]) 
            i--;
        sort(num.begin() + i, num.end());
        if (i == 0) 
            return;
        int j = i;
        while (j < num.size() && num[j] <= num[i-1])
            j++;
        swap(num[j], num[i-1]);
    }
};