// 30 Substring with Concatenation of All Words 
// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]

// You should return the indices: [0,9].
// (order does not matter).

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		unordered_map<string, int> m;
		for (auto &s : L) m[s]++;
		int lSz = L.size(), wSz = L[0].size(), total = lSz;
		for (int i = 0; i < wSz; i++){
			int start = i;
			for (int j = start; j + wSz <= S.size(); j += wSz){
				string curS = S.substr(j, wSz);
				if (m.count(curS)){
					if (m[curS]>0) {
						m[curS]--; total--;
						if (!total)result.push_back(start);
					}
					else{
						string headS = S.substr(start, wSz);
						m[headS]++; total++;
						start += wSz; j -= wSz;
					}
				}
				else{
					for (; start <= j; start += wSz){
						string curS = S.substr(start, wSz);
						if (m.count(curS)){
							m[curS]++; total++;
						}
					}
				}
			}
			for (; start <S.size(); start += wSz){
				string curS = S.substr(start, wSz);
				if (m.count(curS)){
					m[curS]++; total++;
				}
			}
		}
		return result;
	}
};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) return res;
        int M = S.size(), N = L.size();
        int K = L[0].size();
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        for (int i = 0; i < N; ++i)
            need[L[i]]++;
        for (int i = 0; i <= M - N * K; ++i)
        {
            found.clear();
            int j;
            for (j = 0; j < N; ++j)
            {
                string s = S.substr(i + j * K, K);
                auto it = need.find(s);
                if (it == need.end())
                    break;
                if (it->second <= found[s])
                    break;
                found[s]++;
            }
            if (j == N) res.push_back(i);
        }
        return res;
    }
};
