// 642. Design Search Autocomplete System

// Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

// The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
// The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
// If less than 3 hot sentences exist, then just return as many as you can.
// When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
// Your job is to implement the following functions:

// The constructor function:

// AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

// Now, the user wants to input a new sentence. The following function will provide the next character the user types:

// List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


// Example:
// Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
// The system have already tracked down the following sentences and their corresponding times: 
// "i love you" : 5 times 
// "island" : 3 times 
// "ironman" : 2 times 
// "i love leetcode" : 2 times 
// Now, the user begins another search: 

// Operation: input('i') 
// Output: ["i love you", "island","i love leetcode"] 
// Explanation: 
// There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored. 

// Operation: input(' ') 
// Output: ["i love you","i love leetcode"] 
// Explanation: 
// There are only two sentences that have prefix "i ". 

// Operation: input('a') 
// Output: [] 
// Explanation: 
// There are no sentences that have prefix "i a". 

// Operation: input('#') 
// Output: [] 
// Explanation: 
// The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search. 

// Note:
// The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
// The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
// Please use double-quote instead of single-quote when you write test cases even for a character input.
// Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.

class AutocompleteSystem {
    struct TrieNode {
        unordered_map <char, TrieNode *> next;
        bool isEnd;
        int count;
        TrieNode() : isEnd(false), count(0) {}
    };
    
    TrieNode* root;
    TrieNode* curNode;
    string cur;
    
    void Find(char c) {
        if (curNode->next[c] == nullptr) curNode->next[c] = new TrieNode();
        curNode = curNode->next[c];
    }
    
    void dfs(TrieNode* p, string& buf, vector<pair<int, string>> &canidates) {
        if (p->isEnd) canidates.emplace_back(p->count, buf);
        for (auto&& n : p->next) {
            buf.push_back(n.first);
            dfs(n.second, buf, canidates);
            buf.pop_back();
        }
    }
    
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); ++i) {
            curNode = root;
            for (auto c : sentences[i]) Find(c);
            curNode->isEnd = true;
            curNode->count = times[i];
        }
        curNode = root;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            curNode->isEnd = true;
            ++curNode->count;
            curNode = root;
            cur.clear();
            return {};
        }
        cur += c;
        Find(c);
        vector<string> result;
        string buf;
        vector<pair<int, string>> canidates;
        dfs(curNode, buf, canidates);
        sort(canidates.begin(), canidates.end(), 
             [](pair<int, string> &a, pair<int, string> &b){
                 return a.first > b.first || (a.first == b.first && a.second < b.second);
             });
        for (int i = 0; i < min(3, (int)canidates.size()); ++i) {
            result.push_back(cur + canidates[i].second);
        }
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

public class AutocompleteSystem {
    class TrieNode {
        Map<Character, TrieNode> children;
        Map<String, Integer> counts;
        boolean isWord;
        public TrieNode() {
            children = new HashMap<Character, TrieNode>();
            counts = new HashMap<String, Integer>();
            isWord = false;
        }
    }
    
    class Pair {
        String s;
        int c;
        public Pair(String s, int c) {
            this.s = s; this.c = c;
        }
    }
    
    TrieNode root;
    String prefix;
    
    
    public AutocompleteSystem(String[] sentences, int[] times) {
        root = new TrieNode();
        prefix = "";
        
        for (int i = 0; i < sentences.length; i++) {
            add(sentences[i], times[i]);
        }
    }
    
    private void add(String s, int count) {
        TrieNode curr = root;
        for (char c : s.toCharArray()) {
            TrieNode next = curr.children.get(c);
            if (next == null) {
                next = new TrieNode();
                curr.children.put(c, next);
            }
            curr = next;
            curr.counts.put(s, curr.counts.getOrDefault(s, 0) + count);
        }
        curr.isWord = true;
    }
    
    public List<String> input(char c) {
        if (c == '#') {
            add(prefix, 1);
            prefix = "";
            return new ArrayList<String>();
        }
        
        prefix = prefix + c;
        TrieNode curr = root;
        for (char cc : prefix.toCharArray()) {
            TrieNode next = curr.children.get(cc);
            if (next == null) {
                return new ArrayList<String>();
            }
            curr = next;
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> (a.c == b.c ? a.s.compareTo(b.s) : b.c - a.c));
        for (String s : curr.counts.keySet()) {
            pq.add(new Pair(s, curr.counts.get(s)));
        }

        List<String> res = new ArrayList<String>();
        for (int i = 0; i < 3 && !pq.isEmpty(); i++) {
            res.add(pq.poll().s);
        }
        return res;
    }
}