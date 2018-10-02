// 677. Map Sum Pairs

// Implement a MapSum class with insert, and sum methods.

// For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

// For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

// Example 1:
// Input: insert("apple", 3), Output: Null
// Input: sum("ap"), Output: 3
// Input: insert("app", 2), Output: Null
// Input: sum("ap"), Output: 5

class MapSum {
    struct TrieNode {
        vector<TrieNode*> children;
        int val;
        TrieNode () : children(26), val(0) {}
    };
    TrieNode* root;
    
    int dfs(TrieNode* cur) {
        if (cur == nullptr) return 0;
        int res = 0;
        for (auto c : cur->children) {
            res += dfs(c);
        }
        res += cur->val;
        return res;
    }
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        auto cur = root;
        for (auto c : key) {
            if (cur->children[c - 'a'] == nullptr) cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->val = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        auto cur = root;
        for (auto c : prefix) {
            if (cur->children[c - 'a'] == nullptr) return 0;
            cur = cur->children[c - 'a'];
        }
        return dfs(cur);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */


/** Initialize your data structure here. */
Map<String, Integer> map;
Map<String, Integer> original;
public MapSum() {
    map = new HashMap<>();
    original = new HashMap<>();
}

public void insert(String key, int val) {
    val -= original.getOrDefault(key, 0); // calculate the diff to be added to prefixes
    String s = "";
    for(char c : key.toCharArray()) {
        s += c; // creating all prefixes
        map.put(s, map.getOrDefault(s, 0) + val); //update/insert all prefixes with new value
    }
    original.put(key, original.getOrDefault(key, 0) + val);
}

public int sum(String prefix) {
    return map.getOrDefault(prefix, 0);
}