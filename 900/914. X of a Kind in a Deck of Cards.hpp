// 914. X of a Kind in a Deck of Cards

// In a deck of cards, each card has an integer written on it.

// Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

// Each group has exactly X cards.
// All the cards in each group have the same integer.
 

// Example 1:

// Input: [1,2,3,4,4,3,2,1]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
// Example 2:

// Input: [1,1,1,2,2,2,3,3]
// Output: false
// Explanation: No possible partition.
// Example 3:

// Input: [1]
// Output: false
// Explanation: No possible partition.
// Example 4:

// Input: [1,1]
// Output: true
// Explanation: Possible partition [1,1]
// Example 5:

// Input: [1,1,2,2,2,2]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[2,2]

// Note:

// 1 <= deck.length <= 10000
// 0 <= deck[i] < 10000
 
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;
        for (auto card : deck) m[card]++;
        auto gcd = (*m.begin()).second;
        for (auto e : m) {
            gcd = __gcd(e.second, gcd);
        }
        return gcd > 1;
    }
};
// __gcd(x, 0) = x
  bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }

    def gcd(a, b):
            while b: a, b = b, a % b
            return a