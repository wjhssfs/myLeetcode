// 432. All O`one Data Structure
// Implement a data structure supporting the following operations:

// Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
// GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
// GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
// Challenge: Perform all these in O(1) time complexity.

class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (!dataMap.count(key)) {
			if (orderList.size() && orderList.back().first == 1) {
				orderList.back().second.insert(key);
				dataMap[key] = prev(orderList.end());
			}
			else {
				orderList.push_back(make_pair(1, unordered_set<string>({ key })));
				dataMap[key] = prev(orderList.end());
			}
		}
		else {
			auto it = dataMap[key];
			if (it != orderList.begin() && prev(it)->first == it->first + 1) {
				prev(it)->second.insert(key);
				dataMap[key] = prev(it);
			}
			else {
				orderList.insert(it, make_pair(it->first + 1, unordered_set<string>({ key })));
				dataMap[key] = prev(it);
			}
			it->second.erase(key);
			if (it->second.empty()) {
				orderList.erase(it);
			}
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (!dataMap.count(key)) return;
		auto it = dataMap[key];
		if (it->first == 1) {
			it->second.erase(key);
			if (it->second.empty()) {
				orderList.erase(it);
			}
			dataMap.erase(key);
		}
		else {
			if (next(it) != orderList.end() && next(it)->first == it->first - 1) {
				next(it)->second.insert(key);
				dataMap[key] = next(it);
			}
			else {
				orderList.insert(next(it), make_pair(it->first - 1, unordered_set<string>({ key })));
				dataMap[key] = next(it);
			}

			it->second.erase(key);
			if (it->second.empty()) {
				orderList.erase(it);
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (orderList.empty()) return "";
		return *orderList.front().second.begin();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (orderList.empty()) return "";
		return *orderList.back().second.begin();
	}

private:
	unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> dataMap;
	list<pair<int, unordered_set<string>>> orderList;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */