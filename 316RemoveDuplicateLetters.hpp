// 316. Remove Duplicate Letters

// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n[256] = {};
		bool in[256] = {};
		for (char c : s) ++n[c];
		stack<char> rs;
		for (char c : s) {
			if (rs.empty()) {
				rs.push(c);
				in[c] = true;
			}
			else if (!in[c]) {
					while (!rs.empty() && n[rs.top()] > 0 && c < rs.top()) {
						in[rs.top()] = false;
						rs.pop();
					}
					rs.push(c);
					in[c] = true;
			}
			--n[c];
		}

		string result;
		while (!rs.empty()) {
			result += rs.top();
			rs.pop();
		}
		reverse(result.begin(), result.end());
		return result;
    }
};