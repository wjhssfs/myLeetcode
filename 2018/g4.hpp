g4

class Solution {
public:
	multiset<int> m;
	deque<multiset<int>::iterator> q;
	int sum = 0, N = 5, scopedSum = 0;
	void insert(int v) {
		auto r = m.insert(v);
		q.push_back(r);
		sum += v;
		int excludeSize = q.size() / 5;

		if (q.size() > N) {
			sum -= *q.front();
			m.erase(q.front());
			q.pop_front();
		}

		int leftSum = 0, rightSum = 0;
		auto itL = m.begin();
		auto itR = m.rbegin();
		for (int i = 0; i < excludeSize; ++i) {
			leftSum += *itL++;
			rightSum += *itR++;
		}

		scopedSum = sum - leftSum - rightSum;
	}
	int getSum() {
		return scopedSum;
	}
};