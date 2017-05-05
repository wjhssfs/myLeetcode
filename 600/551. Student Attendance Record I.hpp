// 551. Student Attendance Record I
// You are given a string representing an attendance record for a student. The record only contains the following three characters:

// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

// You need to return whether the student could be rewarded according to his attendance record.

// Example 1:
// Input: "PPALLP"
// Output: True
// Example 2:
// Input: "PPALLL"
// Output: False

class Solution {
public:
    bool checkRecord(string s) {
        int nA = 0, nL = 0;
        for (auto c : s) {
            if (c == 'L') {
                ++nL;
                if (nL == 3) return false;
            } else if (c == 'A') {
                ++nA;
                if (nA == 2) return false;
                nL = 0;
            } else nL = 0;
        }
        return true;
    }
};