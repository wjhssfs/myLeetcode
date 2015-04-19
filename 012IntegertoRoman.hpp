// 12 Integer to Roman 
// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
	string intToRoman(int num) {
		string result;
		vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> romanChars = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		for (int i = 0; i < (int)values.size(); i++){
			if (num / values[i]){
				num / values[i] == 1 ? result += romanChars[i] : result += string(num / values[i], romanChars[i].c_str()[0]);
				num %= values[i];
			}
		}
		return result;
	}
};

class Solution2 {
public:
    const string rom[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}};
    string intToRoman(int num) {
        string res;
        int i = 3;
        while (num > 0)
        {
            int divisor = (int)pow(10, i);
            res += rom[i][num / divisor];
            num %= divisor;
            i--;
        }
        return res;
    }
};
