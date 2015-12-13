// 306 Additive Number

// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

// For example:
// "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
// 1 + 99 = 100, 99 + 100 = 199
// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

// Follow up:
// How would you handle overflow for very large input integers?


class Solution {
public:
	bool isAdditiveNumber(string num) {
		if (num.size() < 3) return false;
		for (int i = 0; i < (int)num.size() - 2 && i < 17; i++) {
			if (i > 0 && num[0] == '0') continue;
			unsigned long long first = stoull(num.substr(0, i + 1));
			for (int j = i + 1; j < (int)num.size() - 1 && j - i < 18; j++) {
				if (j > i + 1 && num[i+1] == '0') continue;
				unsigned long long second = stoull(num.substr(i + 1, j - i));
				if (check(num, first, second, j + 1))
					return true;
			}
		}
		return false;
	}

	bool check(string &num, unsigned long long first, unsigned long long second, int start) {
		if (start >= num.size() || num[start] == '0') return false;
		unsigned long long third = first + second;
		string thirdStr = to_string(third);
		if (num.substr(start, thirdStr.size()) == thirdStr) {
			if (start + thirdStr.size() == num.size()) return true;
			else return check(num, second, third, start + thirdStr.size());
		}
		else
			return false;
	}
};