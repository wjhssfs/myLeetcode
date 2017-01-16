// 460. LFU Cache
// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Follow up:
// Could you do both operations in O(1) time complexity?

class LFUCache {
	list<pair<int, list<int>>> fList;
	struct Record {
		int v;
		list<pair<int, list<int>>>::iterator fIt;
		list<int>::iterator lIt;
	};
	unordered_map<int, Record> m;
	int capacity;
public:
	LFUCache(int capacity) : capacity(capacity){
	}

	int get(int key) {
		if (!m.count(key)) return -1;
		auto && r = m[key];
		int newCount = (*r.fIt).first + 1;
		if (r.fIt == fList.begin() || prev(r.fIt)->first != newCount) {
			fList.insert(r.fIt, make_pair(newCount, list<int>()));
		}
		auto nFIt = prev(r.fIt);
		(*nFIt).second.splice((*nFIt).second.begin(), (*r.fIt).second, r.lIt);
		if (r.fIt->second.empty()) fList.erase(r.fIt);
		r.fIt = nFIt;
		return r.v;
	}

	void put(int key, int value) {
		if (capacity < 1) return;
		if (!m.count(key)) {
		    if (m.size() == capacity) {
    			auto keyToBeDeleted = fList.back().second.back();
    			fList.back().second.erase(prev(fList.back().second.end()));
    			if (fList.back().second.empty()) fList.pop_back();
    			m.erase(keyToBeDeleted);
		    }
			fList.push_back(make_pair(0, list<int>({ key })));
			m[key] = { value, prev(fList.end()), fList.back().second.begin()};
		}
		get(key);
        m[key].v = value;
	}
};

// faster, only need minFreq
struct Node
{
	int freq;
	int val;
	list<int>::iterator iter;

	Node() : val(-1), freq(1) {}
	Node(int value) : val(value), freq(1) {}
};
class LFUCache {
	int cap;
	int minFreq;
	unordered_map<int, Node> m; //key to {freq, val, it};
	unordered_map<int, list<int>>  fm;  //freq to key list;
public:
	LFUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (m.count(key) == 0) return -1;

		fm[m[key].freq].erase(m[key].iter);
		m[key].freq++;
		fm[m[key].freq].push_front(key);
		m[key].iter = fm[m[key].freq].begin();

		if (fm[minFreq].size() == 0)
			minFreq = m[key].freq;
		return m[key].val;
	}

	void put(int key, int value) {
		if (cap <= 0) return;

		int storedValue = get(key);
		if (storedValue != -1)
		{
			m[key].val = value;
			return;
		}

		if (m.size() >= cap)
		{
			m.erase(fm[minFreq].back());
			fm[minFreq].pop_back();
		}
		m[key] = { Node(value) };
		fm[1].push_front(key);
		m[key].iter = fm[1].begin();
		minFreq = 1;
	}
};