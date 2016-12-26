// 444. Sequence Reconstruction
// Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

// Example 1:

// Input:
// org: [1,2,3], seqs: [[1,2],[1,3]]

// Output:
// false

// Explanation:
// [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
// Example 2:

// Input:
// org: [1,2,3], seqs: [[1,2]]

// Output:
// false

// Explanation:
// The reconstructed sequence can only be [1,2].
// Example 3:

// Input:
// org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

// Output:
// true

// Explanation:
// The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
// Example 4:

// Input:
// org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

// Output:
// true

class Solution {
public:
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		if (seqs.empty()) return false;
		vector<set<int>> precede(org.size() + 1);
		vector<int> nIn(org.size() + 1);
		for (auto && seq : seqs) {
			if (seq.size() && (seq.front() < 0 || seq.front() > org.size())) return false;
			for (int i = 0; i < (int)seq.size() - 1; ++i) {
				if (seq[i] < 0 || seq[i] > org.size()) return false;
				int j = i + 1;
				if (precede[seq[i]].count(seq[j])) continue;
				precede[seq[i]].insert(seq[j]);
				++nIn[seq[j]];
			}
		}
		int start = -1;
		for (int i = 1; i <= org.size(); ++i) {
			if (nIn[i] == 0) {
				if (start != -1) return false;
				start = i;
			}
		}

		if (start != org[0]) return false;
		for (int i = 1; i < (int)org.size(); ++i) {
			int nextStart = -1;
			for (auto next : precede[start]) {
				if (nIn[next] == 1) {
					if (nextStart != -1) return false;
					nextStart = next;
				}
				--nIn[next];
			}
			if (nextStart != org[i]) return false;
			start = nextStart;
		}
		return true;
	}
};

// https://discuss.leetcode.com/topic/65633/very-short-solution-with-explanation/2
def sequenceReconstruction(self, org, seqs):
    index = {num: i for i, num in enumerate([None] + org)}
    need = set(zip([None] + org, org))
    have = [pair for seq in seqs for pair in zip([None] + seq, seq)]
    return need <= set(have) and all(index[a] < index.get(b, 0) for a, b in have)

// https://discuss.leetcode.com/topic/65961/simple-solution-one-pass-using-only-array-c-92ms-java-16ms/2
class Solution {
public:
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size()+1);
        for(int i=0;i<org.size();++i) pos[org[i]] = i;
        
        vector<char> flags(org.size()+1,0);
        int toMatch = org.size()-1;
        for(const auto& v : seqs) {
            for(int i=0;i<v.size();++i) {
                if(v[i] <=0 || v[i] >org.size())return false;
                if(i==0)continue;
                int x = v[i-1], y = v[i];
                if(pos[x] >= pos[y]) return false;
                if(flags[x] == 0 && pos[x]+1 == pos[y]) flags[x] = 1, --toMatch;
            }
        }
        return toMatch == 0;
	}
};