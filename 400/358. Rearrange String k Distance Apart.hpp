// 358. Rearrange String k Distance Apart

// Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

// All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

// Example 1:
// s = "aabbcc", k = 3

// Result: "abcabc"

// The same letters are at least distance 3 from each other.
// Example 2:
// s = "aaabc", k = 3 

// Answer: ""

// It is not possible to rearrange the string.
// Example 3:
// s = "aaadbbcc", k = 2

// Answer: "abacabcd"

// Another possible answer is: "abcabcda"

// The same letters are at least distance 2 from each other.

class Solution {
public:
	string rearrangeString(string s, int k) {
		if (k <= 1) return s;
		vector<int> feq(128);
		for (auto c : s) feq[c]++;
		priority_queue<pair<int, char>> pq;
		for (int i = 'a'; i <= 'z'; ++i) {
			if (feq[i])pq.emplace(feq[i], i);
		}
		string res;
		queue<pair<int, char>> coolDown;
		while (res.size() < s.size()) {
		    if (pq.empty()) return "";
			auto cur = pq.top();
			pq.pop();
			--cur.first;
			coolDown.push(cur);
			res += cur.second;
			if (coolDown.size() == k) {
				auto ret = coolDown.front();
				coolDown.pop();
				if (ret.first) pq.emplace(ret);
			}
		}
		return res;
	}
};

class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0) return str;
        int length = (int)str.size(); 
        
        string res;
        unordered_map<char, int> dict;
        priority_queue<pair<int, char>> pq;
        
        for(char ch : str) dict[ch]++;
        for(auto it = dict.begin(); it != dict.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        
        while(!pq.empty()){
            vector<pair<int, char>> cache; //store used char during one while loop
            int count = min(k, length); //count: how many steps in a while loop
            for(int i = 0; i < count; i++){
                if(pq.empty()) return "";
                auto tmp = pq.top();
                pq.pop();
                res.push_back(tmp.second);
                if(--tmp.first > 0) cache.push_back(tmp);
                length--;
            }
            for(auto p : cache) pq.push(p);
        }
        return res;
    }
};


// https://discuss.leetcode.com/topic/48260/java-15ms-solution-with-two-auxiliary-array-o-n-time

public class Solution {
    public String rearrangeString(String str, int k) {
        int length = str.length();
        int[] count = new int[26];
        int[] valid = new int[26];
        for(int i=0;i<length;i++){
            count[str.charAt(i)-'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for(int index = 0;index<length;index++){
            int candidatePos = findValidMax(count, valid, index);
            if( candidatePos == -1) return "";
            count[candidatePos]--;
            valid[candidatePos] = index+k;
            sb.append((char)('a'+candidatePos));
        }
        return sb.toString();
    }
    
   private int findValidMax(int[] count, int[] valid, int index){
       int max = Integer.MIN_VALUE;
       int candidatePos = -1;
       for(int i=0;i<count.length;i++){
           if(count[i]>0 && count[i]>max && index>=valid[i]){
               max = count[i];
               candidatePos = i;
           }
       }
       return candidatePos;
   }
}