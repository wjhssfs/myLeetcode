// 904. Fruit Into Baskets

// In a row of trees, the i-th tree produces fruit with type tree[i].

// You start at any tree of your choice, then repeatedly perform the following steps:

// Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
// Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
// Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

// You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

// What is the total amount of fruit you can collect with this procedure?

 

// Example 1:

// Input: [1,2,1]
// Output: 3
// Explanation: We can collect [1,2,1].
// Example 2:

// Input: [0,1,2,2]
// Output: 3
// Explanation: We can collect [1,2,2].
// If we started at the first tree, we would only collect [0, 1].
// Example 3:

// Input: [1,2,3,2,2]
// Output: 4
// Explanation: We can collect [2,3,2,2].
// If we started at the first tree, we would only collect [1, 2].
// Example 4:

// Input: [3,3,3,1,2,1,1,2,3,3,4]
// Output: 5
// Explanation: We can collect [1,2,1,1,2].
// If we started at the first tree or the eighth tree, we would only collect 4 fruits.
 

// Note:

// 1 <= tree.length <= 40000
// 0 <= tree[i] < tree.length

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0, j = 0; j < tree.size(); ++j) {
            m[tree[j]]++;
            if (m.size() <= 2) {res = max(res, j - i + 1); continue;}
            while(m.size() > 2) {
                int v = tree[i++];
                if (--m[v] == 0) m.erase(v);
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/fruit-into-baskets/discuss/170745/Problem:-Longest-Subarray-With-2-Elements
int totalFruit(vector<int> tree) {
        int res = 0, cur = 0, count_b = 0/*# of trailing b*/, a = 0, b = 0;
        for (int c :  tree) {
            cur = c == a || c == b ? cur + 1 : count_b + 1;
            count_b = c == b ? count_b + 1 : 1;
            if (b != c) a = b, b = c;
            res = max(res, cur);
        }
        return res;
    }