// 282 Expression Add Operators

// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

// Examples: 
// "123", 6 -> ["1+2+3", "1*2*3"] 
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> results;
		for (int i = 0; i < (int)num.size(); i++) {
			string n = num.substr(0, i + 1);
			long long nVal = stoll(n);
			DFS(results, num, i+1, n, 0, nVal, target);
			if (num[0] == '0') break;
		}
		return results;
	}

private:
	void DFS(vector<string> &results, string num, int start, string cur, long long valL, long long valB, int target) {
		if (start == num.size() &&  valL + valB == target){
			results.push_back(cur);
		}
		else {
			for (int i = start; i < (int)num.size(); i++) {
				string n = num.substr(start, i - start + 1);
				long long nVal = stoll(n);
				DFS(results, num, i  + 1, cur + "+" + n, valL + valB, nVal, target);
				DFS(results, num, i  + 1, cur + "-" + n, valL + valB, -nVal, target);
				DFS(results, num, i  + 1, cur + "*" + n, valL, valB * nVal, target);
				if (num[start] == '0') break;
			}
		}
	}
};