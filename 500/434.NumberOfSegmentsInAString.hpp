// 434. Number of Segments in a String
// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
// Please note that the string does not contain any non-printable characters.
// Example:
// Input: "Hello, my name is John"
// Output: 5
class Solution {
public:
    int countSegments(string s) {
        int total = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] != ' ' && (i==0 || s[i-1] == ' ')) ++total;
        }
        return total;
    }
};