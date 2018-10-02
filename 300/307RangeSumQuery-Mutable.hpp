// 307 Range Sum Query - Mutable

// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.
// Example:
// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

class NumArray {
	struct Node {
		int val;
		Node *left, *right, *parent;
		int start, end;
		Node(int val, Node *left, Node *right, Node * parent, int start, int end) :
			val(val), left(left), right(right), parent(parent), start(start), end(end) {};
	};
	Node *root;
	vector<Node *> m;
public:
	NumArray(vector<int> &nums) {
		queue<Node *> q, q1;
		for (int i = 0; i < nums.size(); i++) {
			Node *newNode = new Node(nums[i], nullptr, nullptr, nullptr, i, i);
			q.push(newNode);
			m.push_back(newNode);
		}
		while (q.size() > 1) {
			while (q.size() > 1) {
				auto left = q.front(); q.pop();
				auto right = q.front(); q.pop();
				Node *newNode = new Node(left->val + right->val, left, right, nullptr, left->start, right->end);
				left->parent = newNode; right->parent = newNode;
				q1.push(newNode);
			}
			if (q.size() == 1) {
				q1.push(q.front()); q.pop();
			}
			swap(q, q1);
		}
		root = q.size() ? q.front() : nullptr;
	}

	void update(int i, int val) {
		int diff = val - m[i]->val;
		Node *cur = m[i];
		while (cur) {
			cur->val += diff;
			cur = cur->parent;
		}
	}

	int sumRange(int i, int j) {
		return sumRange(i, j, root);
	}

	int sumRange(int i, int j, Node *cur) {
		if (!cur) return 0;
		if (i <= cur->start && j >= cur->end) return cur->val;
		if (j < cur->start || i > cur->end) return 0;
		return sumRange(i, j, cur->left) + sumRange(i, j, cur->right);
	}
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


class NumArray {
public:
    NumArray(vector<int> &nums) {
        ns.resize(nums.size());
        n = (int)ns.size();
        BIT.resize(n+1);
        for(int i = 0; i < n; i++) update(i, nums[i]);
    }

    void update(int i, int val) {
        int diff = val - ns[i];
        ns[i] = val;
        ++i;
        while(i <= n){
            BIT[i] += diff;
            i += (i & -i);
        }
    }

    int sumRange(int i, int j) {
        return sumToI(j) - sumToI(i-1);
    }
private:
    vector<int> BIT, ns;
    int n;
    int sumToI(int i){
        int s = 0;
        ++i;
        while(i > 0) {
            s += BIT[i];
            i -= (i & -i);
        }
        return s;
    }
};