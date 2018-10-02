// 846. Hand of Straights
// Alice has a hand of cards, given as an array of integers.

// Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

// Return true if and only if she can.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
// Example 2:

// Input: hand = [1,2,3,4,5], W = 4
// Output: false
// Explanation: Alice's hand can't be rearranged into groups of 4.
 

// Note:

// 1 <= hand.length <= 10000
// 0 <= hand[i] <= 10^9
// 1 <= W <= hand.length

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) return true;
        sort(hand.begin(), hand.end());
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < (int)hand.size(); ++i) {
            if (pq.size()) {
                auto top = pq.top();
                if (hand[i] > -top.first) return false;
                else if (hand[i] == -top.first) {
                    pq.pop();
                    if (top.second > 1)
                        pq.emplace(top.first - 1, top.second - 1);
                } else pq.emplace(-(hand[i] + 1), W - 1);
            }
            else
            {
                pq.emplace(-(hand[i] + 1), W - 1);
            }
        }
        
        return pq.empty();
    }
};

    bool isNStraightHand(vector<int> hand, int W) {
        map<int, int> c;
        for (int i : hand) c[i]++;
        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }

    bool isNStraightHand(vector<int> hand, int W) {
        map<int, int> c;
        for (int i : hand) c[i]++;
        queue<int> start;
        int last_checked = -1, opened = 0;
        for (auto it : c) {
            int i = it.first;
            if (opened > 0 && i > last_checked + 1 || opened > c[i]) return false;
            start.push(c[i] - opened);
            last_checked = i, opened = c[i];
            if (start.size() == W) {
                opened -= start.front();
                start.pop();
            }
        }
        return opened == 0;
    }