// 936. Stamping The Sequence

// You want to form a target string of lowercase letters.

// At the beginning, your sequence is target.length '?' marks.  You also have a stamp of lowercase letters.

// On each turn, you may place the stamp over the sequence, and replace every letter in the sequence with the corresponding letter from the stamp.  You can make up to 10 * target.length turns.

// For example, if the initial sequence is "?????", and your stamp is "abc",  then you may make "abc??", "?abc?", "??abc" in the first turn.  (Note that the stamp must be fully contained in the boundaries of the sequence in order to stamp.)

// If the sequence is possible to stamp, then return an array of the index of the left-most letter being stamped at each turn.  If the sequence is not possible to stamp, return an empty array.

// For example, if the sequence is "ababc", and the stamp is "abc", then we could return the answer [0, 2], corresponding to the moves "?????" -> "abc??" -> "ababc".

// Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp within 10 * target.length moves.  Any answers specifying more than this number of moves will not be accepted.

 

// Example 1:

// Input: stamp = "abc", target = "ababc"
// Output: [0,2]
// ([1,0,2] would also be accepted as an answer, as well as some other answers.)
// Example 2:

// Input: stamp = "abca", target = "aabcaca"
// Output: [3,0,1]
 

// Note:

// 1 <= stamp.length <= target.length <= 1000
// stamp and target only contain lowercase letters.

// https://leetcode.com/problems/stamping-the-sequence/discuss/189258/C++-Reverse-Operation-30-ms-better-than-DFS
class Solution {
	size_t revertStamp(string& cur, const string& stamp) {
		for (size_t i = 0, j; i < cur.size(); ++i) {
			bool found = false;
			for (j = 0; j < stamp.size() && i + j < cur.size(); ++j) {
				if (cur[i + j] != stamp[j] && cur[i + j] != '*') break;
				if (cur[i + j] != '*') found = true;
			}
			if (j == stamp.size() && found) {
				cur.replace(i, stamp.size(), stamp.size(), '*');
				return i;
			}
		}
		return cur.size();
	}
public:
	vector<int> movesToStamp(string stamp, string target) {
		vector<int> res;
		string cur = target, goal = string(target.size(), '*');
		while (cur != goal) {
			size_t p = revertStamp(cur, stamp);
			if (p == cur.size()) return {};
			res.push_back(p);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};


class Solution2 {
	vector<int> res;
	unordered_map<int, int> ordered;

	bool dfs(string &stamp, int i, string & target, int j, vector<int> cur) {
		if (cur.size() > target.size()) return false;
		if (i > 0 && i < stamp.size() && j < target.size() && stamp[i] == target[j] && dfs(stamp, i + 1, target, j + 1, cur)) return true;
		if (i == stamp.size() && j == target.size()) {
			unordered_map<int, int> ind;
			for (auto&& e : ordered) {
				ind[e.second]++;
			}
			while (res.size() != cur.size()) {
				for (auto a : cur) {
					if (ind.count(a) == 0 || ind[a] == 0) {
						res.push_back(a);
						if (ordered.count(a))
							--ind[ordered[a]];
						ind[a] = -1;
					}
				}
			}
			return true;
		}
		if (j == target.size()) return false;
		for (int k = 0; k < stamp.size(); ++k) {
			if (stamp[k] == target[j] && j + stamp.size() - k <= target.size() && (res.empty() || res.back() < j - k) &&(k == 0 || i == stamp.size())) {
				if (i == stamp.size() && cur.size())
					ordered[j - k] = cur.back();
				cur.push_back(j - k);
				if (dfs(stamp, k + 1, target, j + 1, cur)) return true;
				if (i == stamp.size() && cur.size()) ordered.erase(j - k);
				cur.pop_back();
			}
		}
		return false;
	}
public:
	vector<int> movesToStamp(string stamp, string target) {
		dfs(stamp, 0, target, 0, {});
		return res;
	}
};
