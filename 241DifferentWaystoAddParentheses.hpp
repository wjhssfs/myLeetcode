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
