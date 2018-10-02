// 537. Complex Number Multiplication
// Total Accepted: 2635
// Total Submissions: 3981
// Difficulty: Medium
// Contributors:
// µsic_forever
// Given two strings representing two complex numbers.

// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

// Example 1:
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
// Example 2:
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
// Note:

// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto pa = a.find("+"), pb = b.find("+");
        int al = stoi(a.substr(0, pa)), ar = stoi(a.substr(pa + 1));
        int bl = stoi(b.substr(0, pb)), br = stoi(b.substr(pb + 1));
        int rl = al * bl - ar * br, rr = al * br + bl * ar;
        return to_string(rl) + "+" + to_string(rr) + "i";
    }
};
