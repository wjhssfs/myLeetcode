// 777. Swap Adjacent in LR String
// In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

// Example:

// Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
// Output: True
// Explanation:
// We can transform start to end following these steps:
// RXXLRXRXL ->
// XRXLRXRXL ->
// XRLXRXRXL ->
// XRLXXRRXL ->
// XRLXXRRLX
// Note:

// 1 <= len(start) = len(end) <= 10000.
// Both start and end will only consist of characters in {'L', 'R', 'X'}.

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        int i = 0, j = 0;
        while (true) {
            while (i < start.size() && start[i] == 'X') ++i;
            while (j < end.size() && end[j] == 'X') ++j;
            if (i == start.size() || j == end.size()) break;
            if (start[i] != end[j]) return false;
            cout << i << " " << j << " " << start[i] << endl;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i; ++j;
        }
        return i == start.size() && j == end.size();
    }
};