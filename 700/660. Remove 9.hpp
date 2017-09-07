// 660. Remove 9

// Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...

// So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...

// Given a positive integer n, you need to return the n-th integer after removing. Note that 1 will be the first integer.

// Example 1:
// Input: 9
// Output: 10
// Hint: n will not exceed 9 x 10^8.

// This is a radix problem.
// Just change decimal to 9-based.
public int newInteger(int n) {
    return Integer.parseInt(Integer.toString(n, 9));
}

public int newInteger(int n) {
	int ans = 0;
	int base = 1;
		
	while (n > 0){
		ans += n % 9 * base;
		n /= 9;
		base *= 10;
	}
	return ans;
}

class Solution {
public:
	int newInteger(int n) {
		vector<int> d{0};
        int b = 1;
		for (int i = 1; i < 10; ++i) {
			d.push_back(d.back() * 9 + b);
			b *= 10;
		}
		int nPre = 0;
		int delta = getD(n, d) - getD(nPre, d);
		while (delta) {
			nPre = n;
			n += delta;
			delta = getD(n, d) - getD(nPre, d);
		}
		return n;
	}

	int getD(int n, vector<int> &d) {
		string s = to_string(n);
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			res += (s[i] - '0')* d[s.size() - i - 1];
			if (s[i] == '9') {
				res += i + 1 < s.size() ? stoi(s.substr(i + 1)) + 1 : 1;
				break;
			}
		}
		return res;
	}
};