// 336. Palindrome Pairs
// Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list,
// so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
// Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]
// Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> m;
		vector<vector<int>> res;
		for (size_t i = 0; i < words.size(); ++i) {
			m[words[i]] = i;
		}

		for (int i = 0; i < words.size(); ++i) {
			string &word = words[i];
			for (int j = 0; j <= word.size(); ++j)
			{
				string left = word.substr(0, j), right = word.substr(j);
				if (isPalindrome(left)) {
					string rightRev(right.rbegin(), right.rend());
					if (m.count(rightRev) && m[rightRev] != i) {
						res.push_back({ m[rightRev], i });
					}
				}
				if (isPalindrome(right)) {
					string leftRev(left.rbegin(), left.rend());
					if (m.count(leftRev) && m[leftRev] != i && !right.empty()) {
					   // !right.empty() avoids whole word reversed case being processed twice.
						res.push_back({ i, m[leftRev] });
					}
				}
			}
		}
		return res;
	}
private:
	bool isPalindrome(const string &str)
	{
		int i = 0, j = str.size() - 1;
		while (i < j) {
			if (str[i++] != str[j--]) 
				return false;
		}
		return true;
	}
};


// https://discuss.leetcode.com/topic/39585/o-n-k-2-java-solution-with-trie-structure-n-total-number-of-words-k-average-length-of-each-word
private static class TrieNode {
    TrieNode[] next;
    int index;
    List<Integer> list;
    	
    TrieNode() {
    	next = new TrieNode[26];
    	index = -1;
    	list = new ArrayList<>();
    }
}
    
public List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> res = new ArrayList<>();

    TrieNode root = new TrieNode();
    for (int i = 0; i < words.length; i++) addWord(root, words[i], i);
    for (int i = 0; i < words.length; i++) search(words, i, root, res);
    
    return res;
}
    
private void addWord(TrieNode root, String word, int index) {
    for (int i = word.length() - 1; i >= 0; i--) {
        int j = word.charAt(i) - 'a';
    	if (root.next[j] == null) root.next[j] = new TrieNode();
    	if (isPalindrome(word, 0, i)) root.list.add(index);
    	root = root.next[j];
    }
    	
    root.list.add(index);
    root.index = index;
}
    
private void search(String[] words, int i, TrieNode root, List<List<Integer>> res) {
    for (int j = 0; j < words[i].length(); j++) {	
    	if (root.index >= 0 && root.index != i && isPalindrome(words[i], j, words[i].length() - 1)) {
    	    res.add(Arrays.asList(i, root.index));
    	}
    		
    	root = root.next[words[i].charAt(j) - 'a'];
      	if (root == null) return;
    }
    	
    for (int j : root.list) {
    	if (i == j) continue;
    	res.add(Arrays.asList(i, j));
    }
}
    
private boolean isPalindrome(String word, int i, int j) {
    while (i < j) {
    	if (word.charAt(i++) != word.charAt(j--)) return false;
    }
    	
    return true;
}