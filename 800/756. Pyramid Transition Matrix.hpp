// 756. Pyramid Transition Matrix
// We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

// For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

// We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

// Return true if we can build the pyramid all the way to the top, otherwise false.

// Example 1:
// Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
// Output: true
// Explanation:
// We can stack the pyramid like this:
//     A
//    / \
//   D   E
//  / \ / \
// X   Y   Z

// This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
// Example 2:
// Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
// Output: false
// Explanation:
// We can't stack the pyramid to the top.
// Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
// Note:
// bottom will be a string with length in range [2, 8].
// allowed will have length in range [0, 200].
// Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

class Solution {
    bool dfs(string top, string next, unordered_set<string>& allowed) {
        //cout << top << endl;
        if (top.size() == 1 && next.empty()) return true;
        if (next.empty()) swap(top, next);
        for (char i = 'A'; i <= 'G'; ++i) {
            string cur = next.substr(0, 2) + i;
            if (allowed.count(cur)) {
                if (dfs(top + i, next.size() == 2 ? string() : next.substr(1), allowed)) return true;
            }
        }
        return false;
        
    }
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> allow(allowed.begin(), allowed.end());
        return dfs(bottom, {}, allow);
    }
};