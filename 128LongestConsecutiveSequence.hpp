// 128 Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// 
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
// 
// Your algorithm should run in O(n) complexity.

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> v(num.begin(), num.end());
		int maxC = 0;
		while (!v.empty()){
			int curC = 1;
			int key = *v.begin();
			v.erase(key);
			int keyCopy = key;
			while (keyCopy != INT_MAX){
				keyCopy++;
				if (v.count(keyCopy)){
					v.erase(keyCopy);
					curC++;
				}
				else{
					break;
				}
			}
			while (key != INT_MIN){
				key--;
				if (v.count(key)){
					v.erase(key);
					curC++;
				}
				else{
					break;
				}
			}
			maxC = max(curC, maxC);
		}
		return maxC;
	}
};

class Solution2 {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, int> uii;
		int maxlen=0;
		for (auto &val : num) {
			if (uii.find(val) != uii.end()) continue;
			uii[val] = 1;
			int leftbound = 0;
			if (val != INT_MIN && uii.find(val - 1)!=uii.end()) leftbound = uii[val - 1];
			int rightbound = 0;
			if (val != INT_MAX && uii.find(val + 1) != uii.end()) rightbound = uii[val + 1];
			uii[val - leftbound] = uii[val + rightbound] = 1 + leftbound + rightbound;
			maxlen = max(maxlen, 1 + leftbound + rightbound);
		}
		return maxlen;
	}
};


class Solution3 {
public:
    int longestConsecutive(vector<int> &num) {
        return longestConsecutive1(num);
    }
    
    int longestConsecutive1(vector<int> &num) {
        unordered_set<int> s;
        int res = 0;
        for (int i = 0; i < num.size(); ++i)
            s.insert(num[i]);
        for (int i = 0; i < num.size() && !s.empty(); ++i)
        {
            if (s.find(num[i]) == s.end())
                continue;
            int upper = num[i], lower = num[i];
            while (s.find(upper+1) != s.end())
                s.erase(++upper);
            while (s.find(lower-1) != s.end())
                s.erase(--lower);
            if (upper != lower)
                s.erase(num[i]);
            res = max(res, upper - lower + 1);
        }
        return res;
    }
    
    int longestConsecutive2(vector<int> &num) {
        int longest = 0;
        unordered_map<int, int> table;
        for(int i = 0, count = num.size(); i < count; ++i) 
            if(table.find(num[i]) == table.end()) {
                int val = num[i], update;
                if(table.find(val - 1) != table.end() && table.find(val + 1) != table.end())
                    // assigning to table[val] here is only for adding val as a key of the hashtable.
                    update = table[val] = 
                             table[val - table[val - 1]] = 
                             table[val + table[val + 1]] = 
                             table[val - 1] + table[val + 1] + 1; 
                else if(table.find(val - 1) != table.end())
                    update = table[val] = ++table[val - table[val - 1]];
                else if(table.find(val + 1) != table.end())
                    update = table[val] = ++table[val + table[val + 1]];
                else 
                    update = table[val] = 1;
                longest = max(longest, update);
            }
        return longest;
    }
};
