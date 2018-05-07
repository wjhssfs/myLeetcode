// 822. Card Flipping Game

// On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).

// We flip any number of cards, and after we choose one card. 

// If the number X on the back of the chosen card is not on the front of any card, then this number X is good.

// What is the smallest number that is good?  If no number is good, output 0.

// Here, fronts[i] and backs[i] represent the number on the front and back of card i. 

// A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.

// Example:

// Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
// Output: 2
// Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
// We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.
 

// Note:

// 1 <= fronts.length == backs.length <= 1000.
// 1 <= fronts[i] <= 2000.
// 1 <= backs[i] <= 2000.


class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> m(fronts.begin(), fronts.end());
        m.insert(backs.begin(), backs.end());
        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) m.erase(fronts[i]);
        }
        return m.size() ? *m.begin() : 0;
    }
};

  int flipgame(vector<int>& f, vector<int>& b) {
        unordered_set<int> same;
        for (int i = 0; i < f.size(); ++i) if (f[i] == b[i]) same.insert(f[i]);
        int res = 3000;
        for (int & i : f) if (same.count(i) == 0) res = min(res, i);
        for (int & i : b) if (same.count(i) == 0) res = min(res, i);
        return res % 3000;
    }