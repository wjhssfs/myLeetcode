// 318. Maximum Product of Word Lengths

// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".

// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".

// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int nWords = words.size();
		if (!nWords)
			return 0;
		sort(words.begin(), words.end(), [](string &a, string &b) {return a.size() > b.size(); });
		vector<int> m(nWords);
		for (int i = 0; i < nWords; i++) {
			for (int j = 0; j < words[i].size(); j++) {
				m[i] |= (1 << (words[i][j] - 'a'));
			}
		}
		int maxProduct = 0;
		int right = nWords;
		for (int i = 0; i < nWords - 1; i++) {
			for (int j = i + 1; j < right; j++) {
				bool shareCommon = false;
				if (!(m[i] & m[j])) {
					int curProduct = words[i].size() * words[j].size();
					maxProduct = max(maxProduct, curProduct);
					right = j + 1;
					break;
				}
			}
		}
		return maxProduct;
	}
};

class Solution {
public:
	int maxProduct(vector<string>& words) {
	    vector<int> mask(words.size());
	    int result = 0;
	    for (int i=0; i<words.size(); ++i) {
	        for (char c : words[i])
	            mask[i] |= 1 << (c - 'a');
	        for (int j=0; j<i; ++j)
	            if (!(mask[i] & mask[j]))
	                result = max(result, int(words[i].size() * words[j].size()));
	    }
	    return result;
	}
};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> maxlen;
        int result = 0;
        for (string word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            maxlen[mask] = max(maxlen[mask], (int) word.size());
            for (auto maskAndLen : maxlen)
                if (!(mask & maskAndLen.first))
                    result = max(result, (int) word.size() * maskAndLen.second);
        }
        return result;
    }
};