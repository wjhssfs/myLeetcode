// 241 Different Ways to Add Parentheses 

// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


// Example 1
// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]


// Example 2
// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }

    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1, result2;
                string substr = input.substr(0, i);
                // check if dpMap has the result for substr
                if (dpMap.find(substr) != dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = computeWithDP(substr, dpMap);

                substr = input.substr(i + 1);
                if (dpMap.find(substr) != dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = computeWithDP(substr, dpMap);

                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        // save to dpMap
        dpMap[input] = result;
        return result;
    }
};


class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> res, nums; vector<char> ops;
		if (input.empty()) return res;
		stringstream ss(input);
		int n; char op;
		ss >> n; nums.push_back(n);
		while (ss >> op >> n){
			ops.push_back(op);
			nums.push_back(n);
		}
		stack<int> s;
		s.push(nums[0]);
		recurse(res, nums, 1, ops, 0, s, stack<char>());
		return res;
	}
	void recurse(vector<int> & res, vector<int> & nums, int nextN, vector<char> &ops, int nextO, stack<int> ns, stack<char> os){
		if (nextN == nums.size() && nextO == ops.size()){// no more tokens
			while (!os.empty()){
				calcTop(ns, os);
			}
			res.push_back(ns.top());
			return;
		}
		stack<int> ns1(ns); stack<char>os1(os);
		ns1.push(nums[nextN]); os1.push(ops[nextO]);
		recurse(res, nums, nextN + 1, ops, nextO + 1, ns1, os1);

		while (!os.empty()){
			calcTop(ns, os);
			stack<int> ns1(ns); stack<char>os1(os);
			ns1.push(nums[nextN]); os1.push(ops[nextO]);
			recurse(res, nums, nextN + 1, ops, nextO + 1, ns1, os1);
		}
	}

	void calcTop(stack<int> &ns, stack<char> &os){
		int n2 = ns.top(); ns.pop();
		int n1 = ns.top(); ns.pop();
		switch (os.top()){
		case '+':
			ns.push(n1 + n2);
			break;
		case '-':
			ns.push(n1 - n2);
			break;
		case '*':
			ns.push(n1 * n2);
			break;
		}
		os.pop();
	}
};
